// KeyState.cpp by katahiromz
// License: MIT
#include <windows.h>
#include <imm.h>
#include <stdio.h>

int main(void)
{
    printf("Sleeping 5 seconds...\n");
    Sleep(5 * 1000);

    BYTE abKeyState[256];
    if (!GetKeyboardState(abKeyState))
    {
        printf("!GetKeyboardState\n");
        return -1;
    }
    printf("GetKeyboardState:\n");
    for (INT y = 0; y < 16; ++y)
    {
        for (INT x = 0; x < 16; ++x)
        {
            INT code = x + 16 * y;
            printf("%02X ", abKeyState[code]);
        }
        printf("\n");
    }
    return 0;
}
