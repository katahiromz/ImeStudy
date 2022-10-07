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

        printf("---\n");
        printf("hwnd: %p\n", (void *)hwnd);
        printf("hwndChild: %p\n", (void *)hwndChild);
        printf("GetForegroundWindow(): %p\n", (void *)GetForegroundWindow());
        printf("GetFocus(): %p\n", (void *)GetFocus());
        printf("GetActiveWindow(): %p\n", (void *)GetActiveWindow());
        Sleep(1000);
    }
}
