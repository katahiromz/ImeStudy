#include <windows.h>
#include <stdio.h>

int main(void)
{
    if (MessageBox(NULL, TEXT("Please click Yes or No."), TEXT("Hello"), MB_YESNO) == IDYES)
    {
        MessageBox(NULL, TEXT("You clicked Yes."), TEXT("Hello"), 0);
    }
    else
    {
        MessageBox(NULL, TEXT("You clicked No."), TEXT("Hello"), 0);
    }
    return 0;
}
