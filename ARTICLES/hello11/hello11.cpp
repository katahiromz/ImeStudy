#include <windows.h>
#include <imm.h>
#include <stdio.h>

int main(void)
{
    DebugBreak();
    ImmReleaseContext((HWND)0xDEADFACE, (HIMC)0xBEEFCAFE);
    return 0;
}
