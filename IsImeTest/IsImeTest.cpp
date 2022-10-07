// IsImeTest.cpp by katahiromz
// License: MIT
#include <windows.h>
#include <imm.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    HKL hKL;
    if (argc >= 2)
        hKL = (HKL)(UINT_PTR)strtoul(argv[1], NULL, 0);
    else
        hKL = GetKeyboardLayout(0);

    if (ImmIsIME(hKL))
        printf("ImmIsIME(%p): TRUE\n", hKL);
    else
        printf("ImmIsIME(%p): FALSE\n", hKL);
    return 0;
}
