#include <iostream>

int main()
{
    int a;
    printf_s("Enter number ");
    scanf_s("%d", &a);
    if (a % 2 == -1 || a == 8)
        printf_s("yes");
    else
        printf_s("no");
    printf_s("\n");
    return 0;
}
