// UserLang.cpp by katahiromz
// License: MIT
#include <windows.h>
#include <imm.h>
#include <stdio.h>

int main(void)
{
    LANGID langid = GetUserDefaultLangID();
    printf("GetUserDefaultLangID: 0x%X (%d)\n", langid, langid);
    LCID lcid = GetUserDefaultLCID();
    printf("GetUserDefaultLCID: 0x%X (%d)\n", lcid, lcid);
    return 0;
}
