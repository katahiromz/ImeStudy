// License: MIT
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <imm.h>
#include <shlwapi.h>
#include "ImeMenu.h"

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
    }
}

void ShowImeMenu(HWND hWnd, HIMC hIMC, BOOL bRight)
{
    PIMEMENUNODE pMenu = CreateImeMenu(hWnd, hIMC, NULL, bRight);
    HMENU hMenu = MenuFromImeMenu(pMenu);
    if (hMenu)
    {
        DWORD dwPos = (DWORD)GetMessagePos();
        INT nCmd = TrackPopupMenuEx(hMenu,
                                    TPM_RETURNCMD | TPM_NONOTIFY |
                                    TPM_LEFTBUTTON | TPM_LEFTALIGN | TPM_TOPALIGN,
                                    LOWORD(dwPos), HIWORD(dwPos),
                                    hWnd, NULL);
        if (nCmd)
        {
            INT nRealID = GetRealImeMenuID(pMenu, nCmd);

            MENUITEMINFO mii = { sizeof(mii), MIIM_DATA };
            GetMenuItemInfo(hMenu, nCmd, FALSE, &mii);

            ImmNotifyIME(hIMC, NI_IMEMENUSELECTED, nRealID, mii.dwItemData);
        }
    }
    else
    {
        MessageBoxA(NULL, "FAILED", NULL, MB_ICONERROR);
    }

    CleanupImeMenus();
    DestroyMenu(hMenu);
}

void OnLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
    POINT pt = { x, y };
    ClientToScreen(hwnd, &pt);

    HIMC hIMC = ImmGetContext(hwnd);
    if (hIMC)
    {
        ShowImeMenu(hwnd, hIMC, FALSE);
        ImmReleaseContext(hwnd, hIMC);
    }
}

void OnRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
    POINT pt = { x, y };
    ClientToScreen(hwnd, &pt);

    HIMC hIMC = ImmGetContext(hwnd);
    if (hIMC)
    {
        ShowImeMenu(hwnd, hIMC, TRUE);
        ImmReleaseContext(hwnd, hIMC);
    }
}

INT_PTR CALLBACK
DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_INITDIALOG, OnInitDialog);
        HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
        HANDLE_MSG(hwnd, WM_LBUTTONDOWN, OnLButtonDown);
        HANDLE_MSG(hwnd, WM_RBUTTONDOWN, OnRButtonDown);
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

#if (WINVER >= 0x0500)
    HANDLE hProcess = GetCurrentProcess();
    TCHAR szText[MAX_PATH];

    wnsprintf(szText, _countof(szText), TEXT("Count of GDI objects: %ld\n"), GetGuiResources(hProcess, GR_GDIOBJECTS));
    OutputDebugString(szText);

    wnsprintf(szText, _countof(szText), TEXT("Count of USER objects: %ld\n"), GetGuiResources(hProcess, GR_USEROBJECTS));
    OutputDebugString(szText);
#endif

#if defined(_MSC_VER) && !defined(NDEBUG)
    // for detecting memory leak (MSVC only)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    return 0;
}
