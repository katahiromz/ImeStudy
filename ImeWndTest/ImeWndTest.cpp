// ImeWndTest.cpp by katahiromz
// License: MIT
#include <windows.h>
#include <windowsx.h>
#include <imm.h>
#include <tchar.h>
#include <stdio.h>
#define MSGDUMP_TPRINTF _tprintf
#include "msgdump.h"

static HINSTANCE s_hInst = NULL;
static HWND s_hwndEdit = NULL;
static HWND s_hImeWnd = NULL;
static WNDPROC s_fnImeOldWndProc = NULL;

LRESULT CALLBACK
ImeWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    MD_msgdump(hwnd, uMsg, wParam, lParam);
    LRESULT ret = CallWindowProcW(s_fnImeOldWndProc, hwnd, uMsg, wParam, lParam);
    MD_msgresult(hwnd, uMsg, wParam, lParam, ret);
    return ret;
}

BOOL OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
    DWORD style, exstyle;
    style = WS_CHILD | WS_VISIBLE | ES_LEFT | ES_AUTOHSCROLL;
    exstyle = WS_EX_CLIENTEDGE;
    s_hwndEdit = CreateWindowExW(exstyle, L"EDIT", NULL, style, 0, 0, 0, 0, hwnd, NULL, s_hInst, NULL);
    if (!s_hwndEdit)
        return FALSE;

    s_hImeWnd = ImmGetDefaultIMEWnd(hwnd);
    s_fnImeOldWndProc = (WNDPROC)SetWindowLongPtrW(s_hImeWnd, GWLP_WNDPROC, (LONG_PTR)ImeWindowProc);

    PostMessageW(hwnd, WM_SIZE, 0, 0);
    return TRUE;
}

void OnSize(HWND hwnd, UINT state, int cx, int cy)
{
    RECT rc;
    GetClientRect(hwnd, &rc);
    MoveWindow(s_hwndEdit, 0, 0, rc.right, rc.bottom, TRUE);
}

void OnDestroy(HWND hwnd)
{
    SetWindowLongPtrW(s_hImeWnd, GWLP_WNDPROC, (LONG_PTR)s_fnImeOldWndProc);
    PostQuitMessage(0);
}

LRESULT CALLBACK
WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
        HANDLE_MSG(hwnd, WM_SIZE, OnSize);
        HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
    default:
        return DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

#define CLASSNAME L"ImeWndTest"

int main(void)
{
    s_hInst = GetModuleHandleW(NULL);

    WNDCLASSEXW wc = { sizeof(wc), CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS, WindowProc };
    wc.hInstance = s_hInst;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
    wc.lpszClassName = CLASSNAME;
    if (!RegisterClassExW(&wc))
    {
        printf("!RegisterClassExW\n");
        return -1;
    }

    DWORD style, exstyle;
    style = WS_OVERLAPPEDWINDOW;
    exstyle = 0;
    HWND hwnd = CreateWindowExW(exstyle, CLASSNAME, L"ImeWndTest", style,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 300,
        NULL, NULL, s_hInst, NULL);
    if (!hwnd)
    {
        printf("!hwnd");
        return -2;
    }

    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessageW(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
