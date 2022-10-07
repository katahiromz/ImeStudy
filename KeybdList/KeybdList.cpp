// KeybdList.cpp by katahiromz
// License: MIT
#include <windows.h>
#include <imm.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    HKL ahKL[64];
    UINT nCount = GetKeyboardLayoutList(64, ahKL);
    printf("GetKeyboardLayoutList nCount: %u\n", nCount);
    for (UINT i = 0; i < nCount; ++i)
    {
        printf("HKL[%u]: %p\n", i, ahKL[i]);
    }
    return 0;
}
