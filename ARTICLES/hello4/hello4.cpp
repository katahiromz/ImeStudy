#include <windows.h>
#include <stdio.h>
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

INT WINAPI
WinMain(HINSTANCE   hInstance,
        HINSTANCE   hPrevInstance,
        LPSTR       lpCmdLine,
        INT         nCmdShow)
{
    if (MessageBox(NULL, doLoadString(IDS_YESORNO), doLoadString(IDS_HELLO), MB_YESNO) == IDYES)
    {
        MessageBox(NULL, doLoadString(IDS_CLICKEDYES), doLoadString(IDS_HELLO), 0);
    }
    else
    {
        MessageBox(NULL, doLoadString(IDS_CLICKEDNO), doLoadString(IDS_HELLO), 0);
    }
    return 0;
}
