// whc.cpp
// This software is public domain software.
// Copyright (C) 2017-2018 Katayama Hirofumi MZ.
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

#define MAX_TEXT 64
#define INDENT 3

int main(void)
{
    POINT pt;
    HWND hwnd, hwndChild;
    std::vector<HWND> vec;
    CHAR szClass[MAX_TEXT], szText[MAX_TEXT];

    std::printf("############################################\n");
    std::printf("WindowHierarchyChecker ver.0.1 by katahiromz\n");
    std::printf("############################################\n\n");

    for (;;)
    {
        GetCursorPos(&pt);
        hwnd = WindowFromPoint(pt);
        hwndChild = ChildWindowFromPointEx(hwnd, pt, CWP_SKIPINVISIBLE);
        if (hwndChild)
            hwnd = hwndChild;

        vec.clear();
        while (hwnd)
        {
            vec.push_back(hwnd);
            hwnd = GetParent(hwnd);
        }

        std::reverse(vec.begin(), vec.end());

        std::printf("---\n");
        for (size_t i = 0; i < vec.size(); ++i)
        {
            hwnd = vec[i];
            std::string str(i * INDENT, ' ');
            GetClassNameA(hwnd, szClass, MAX_TEXT);
            GetWindowTextA(hwnd, szText, MAX_TEXT);
            DWORD style = GetWindowLong(hwnd, GWL_STYLE);
            DWORD exstyle = GetWindowLong(hwnd, GWL_EXSTYLE);
            DWORD cs = GetClassLong(hwnd, GCL_STYLE);
            UINT id = GetWindowLong(hwnd, GWL_ID);
            RECT rc;
            HWND hwndOwner = GetWindow(hwnd, GW_OWNER);
            GetWindowRect(hwnd, &rc);
            std::printf("%sHWND %p, Class '%s', Text '%s' WS_ 0x%08X WS_EX_ 0x%08X CS_ 0x%08X ID %u RC (%ld, %ld) - (%ld, %ld), owner %p\n",
                        str.c_str(), (void *)hwnd, szClass, szText, style, exstyle, cs, id,
                        rc.left, rc.top, rc.right, rc.bottom, hwndOwner);
        }

        Sleep(1500);
    }
}
