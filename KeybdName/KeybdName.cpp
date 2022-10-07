// KeybdName.cpp by katahiromz
// License: MIT
#include <windows.h>
#include <imm.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char sz[KL_NAMELENGTH + 1];
    GetKeyboardLayoutNameA(sz);
    printf("GetKeyboardLayoutNameA: %s\n", sz);
    return 0;
}
