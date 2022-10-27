// This file is public domain software.
#include <windows.h>
#include <stdio.h>

int main(void)
{
    for (;;)
    {
        POINT pt;
        GetCursorPos(&pt);
        HWND hwnd = WindowFromPoint(pt);
        HWND hwndChild = ChildWindowFromPointEx(hwnd, pt, CWP_SKIPINVISIBLE);
        CHAR szClass[128], szChildClass[128];
        GetClassNameA(hwnd, szClass, _countof(szClass));
        GetClassNameA(hwndChild, szChildClass, _countof(szChildClass));
        CHAR szText[128], szChildText[128];
        GetWindowTextA(hwnd, szText, _countof(szText));
        GetWindowTextA(hwndChild, szChildText, _countof(szChildText));

        printf("---\n");
        printf("hwnd: %p (%s) - '%s'\n", (void *)hwnd, szClass, szText);
        printf("hwndChild: %p (%s) - '%s'\n", (void *)hwndChild, szChildClass, szChildText);
        printf("GetForegroundWindow(): %p\n", (void *)GetForegroundWindow());
        printf("GetFocus(): %p\n", (void *)GetFocus());
        printf("GetActiveWindow(): %p\n", (void *)GetActiveWindow());
        Sleep(1000);
    }
}
