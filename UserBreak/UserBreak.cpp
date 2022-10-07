// KeyState.cpp by katahiromz
// License: MIT
#include <windows.h>
#include <imm.h>
#include <stdio.h>

int main(void)
{
    MessageBeep(0xFFFFFFFF);
    ImmReleaseContext(NULL, NULL);
    DebugBreak();
    return 0;
}
