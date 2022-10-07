#include <windows.h>
#include <imm.h>
#include <stdio.h>

int main(void)
{
    HIMC hIMC;
    BOOL ret;
    printf("ImmCreateContext: %p\n", ImmCreateContext);
    printf("ImmDestroyContext: %p\n", ImmDestroyContext);
    fflush(stdout);
    DebugBreak();
    hIMC = ImmCreateContext();
    printf("hIMC: %p\n", hIMC);
    ret = ImmDestroyContext(hIMC);
    printf("ret: %d\n", ret);
    return 0;
}
