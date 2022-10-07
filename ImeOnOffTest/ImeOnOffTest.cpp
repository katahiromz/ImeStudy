// ImeOnOffTest.cpp by katahiromz
// License: MIT
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <imm.h>

BOOL OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
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
        {
            HWND hwndEdit = GetDlgItem(hwnd, edt1);
            SetFocus(hwndEdit);
            if (HIMC hIMC = ImmGetContext(hwndEdit))
            {
                ImmSetOpenStatus(hIMC, TRUE);
                ImmReleaseContext(hwndEdit, hIMC);
            }
            SetFocus(hwndEdit);
        }
        break;
    case psh2:
        {
            HWND hwndEdit = GetDlgItem(hwnd, edt1);
            SetFocus(hwndEdit);
            if (HIMC hIMC = ImmGetContext(hwndEdit))
            {
                ImmSetOpenStatus(hIMC, FALSE);
                ImmReleaseContext(hwndEdit, hIMC);
            }
        }
        break;
    case psh3:
        ImmReleaseContext(NULL, NULL);
        DebugBreak();
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
    InitCommonControls();
    DialogBox(hInstance, MAKEINTRESOURCE(1), NULL, DialogProc);
    return 0;
}
