// SysLang.cpp by katahiromz
// License: MIT
#include <windows.h>
#include <imm.h>
#include <stdio.h>

int main(void)
{
    LANGID langid = GetSystemDefaultLangID();
    printf("GetSystemDefaultLangID: 0x%X (%d)\n", langid, langid);
    LCID lcid = GetSystemDefaultLCID();
    printf("GetSystemDefaultLCID: 0x%X (%d)\n", lcid, lcid);
    return 0;
}
