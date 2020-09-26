#include <iostream>

int main()
{
    int number;
    do
    {
        printf_s("Enter number: ");
        scanf_s("%d", &number);
    } while(number < 0);

    int result = 0;
    int i = 0;
    do
    {
        result += number%10;
        number /= 10;
        i++;
    } while (number > 0);
    printf_s("Result = %lf", double(result)/i);
}
