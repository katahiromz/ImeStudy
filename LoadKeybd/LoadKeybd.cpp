// LoadKeybd.cpp by katahiromz
// License: MIT
#include <windows.h>
#include <imm.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3 && argc != 4)
    {
        printf("Usage: LoadKeybd (pwszKLID) (Flags)\n");
        return -1;
    }

    DWORD dwKLID = strtoul(argv[1], NULL, 16);
    DWORD dwFlags = strtoul(argv[2], NULL, 0);

    CHAR szText[32];
    wsprintfA(szText, "%08X", dwKLID);
    HKL hKL = LoadKeyboardLayoutA(szText, dwFlags);
    printf("LoadKeyboardLayoutA(%s, 0x%X) == %p\n", szText, dwFlags, hKL);
    if (!hKL)
        return -2;
    return 0;
}
