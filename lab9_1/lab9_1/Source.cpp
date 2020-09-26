#include <iostream>

int main()
{
    int a;
    printf_s("Enter number: ");
    scanf_s("%d", &a);

    int result = 1;
    for(;a > 0;a--)
    {
        result *= a;
    }
    printf_s("Factorial: %d\n", result);
}
