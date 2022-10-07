#include <windows.h>
#include <windowsx.h>
#include <strsafe.h>
#include "resource.h"

LPCTSTR doLoadString(INT nID)
{
    static TCHAR s_szText[2][MAX_PATH];
    static size_t s_nIndex = 0;
    INT nIndex = s_nIndex;
    s_szText[nIndex][0] = 0;
    LoadString(NULL, nID, s_szText[nIndex], _countof(s_szText[nIndex]));
    s_nIndex = !s_nIndex;
    return s_szText[nIndex];
}

BOOL OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    return TRUE;
}

BOOL OnPsh1(HWND hwnd)
{
    TCHAR szText[MAX_PATH];
    TCHAR szName[64];

    GetDlgItemText(hwnd, edt1, szName, _countof(szName));
    if (szName[0] == 0)
    {
        MessageBox(hwnd, doLoadString(IDS_PLEASEINPUT), NULL, MB_ICONERROR);
        return FALSE;
    }

    StringCchPrintf(szText, _countof(szText), doLoadString(IDS_HELLO), szName);
    SetDlgItemText(hwnd, edt2, szText);
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
