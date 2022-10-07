// EnumLangIDs.cpp by katahiromz
// License: MIT
#include <windows.h>
#include <imm.h>
#include <cstdio>
#include <string>
#include <algorithm>

BOOL CALLBACK EnumLocalesProc(LPSTR lpLocaleString)
{
    LCID lcid = strtoul(lpLocaleString, NULL, 16);

    char szEngLang[256];
    GetLocaleInfoA(lcid, LOCALE_SENGLANGUAGE, szEngLang, _countof(szEngLang));
    char szEngCountry[256];
    GetLocaleInfoA(lcid, LOCALE_SENGCOUNTRY, szEngCountry, _countof(szEngCountry));

    std::string str = szEngLang;
    str += " (";
    str += szEngCountry;
    str += ")";

    char szLang[256];
    GetLocaleInfoA(lcid, LOCALE_SLANGUAGE, szLang, _countof(szLang));

    printf("%s\t%s\t%s\t%s\n", lpLocaleString, std::to_string(lcid).c_str(), str.c_str(), szLang);
    return TRUE;
}

int main(void)
{
    EnumSystemLocalesA(EnumLocalesProc, LCID_SUPPORTED);
    return 0;
}
