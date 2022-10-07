#include <windows.h>
#include <windowsx.h>
#include "resource.h"

void OnPsh1(HWND hwnd)
{
    INT nValue1 = GetDlgItemInt(hwnd, edt1, NULL, TRUE);
    INT nValue2 = GetDlgItemInt(hwnd, edt2, NULL, TRUE);
    INT nValue3 = nValue1 + nValue2;
    SetDlgItemInt(hwnd, edt3, nValue3, TRUE);
}

BOOL OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    SetDlgItemInt(hwnd, edt1, 1, TRUE);
    SetDlgItemInt(hwnd, edt2, 2, TRUE);
    return TRUE;
}

void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id)
    {
    case IDOK:
    case IDCANCEL:
        EndDialog(hwnd, id);
        break;
    case psh1:
        OnPsh1(hwnd);
        break;
    }
}

INT_PTR CALLBACK
DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_INITDIALOG, OnInitDialog);
        HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
    }
    return 0;
}

INT WINAPI
WinMain(HINSTANCE   hInstance,
        HINSTANCE   hPrevInstance,
        LPSTR       lpCmdLine,
        INT         nCmdShow)
{
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, DialogProc);
    return 0;
}
