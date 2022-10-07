#include <windows.h>
#include <stdio.h>

extern "C"
{

int __cdecl cfunc(int a, int b)
{
    return a - b;
}

int __stdcall stdfunc(int a, int b)
{
    return a - b;
}

void ccaller(void)
{
    printf("cfunc: %d\n", cfunc(1, 2));
}

void stdcaller(void)
{
    printf("stdfunc: %d\n", stdfunc(3, 4));
}

} // extern "C"

int main(void)
{
    ccaller();
    stdcaller();
    return 0;
}
