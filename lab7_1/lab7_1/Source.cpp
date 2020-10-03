#include <iostream>

int log(int a, int b)
{
    int c = 0;
    while (b != 1)
    {
        if(b%a != 0) //power is not integer
            return -1;
        b /= a;
        c++;
    }
    return c;
}

int main()
{
    int a, b;
    printf_s("Enter 2 numbers: ");
    scanf_s("%d%d",&a,&b);

    int result = log(a,b);
    if(result == -1)
        printf_s("Impossible");
    else
        printf_s("Result: %d",result);

    printf_s("\n");
    return 0;
}
