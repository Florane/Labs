#include <iostream>

int main()
{
    int number;
    printf_s("Enter number: ");
    scanf_s("%d", &number);

    int result = 0;
    int i = 0;
    while(number > 0)
    {
        result += number%10;
        number /= 10;
        i++;
    }
    printf_s("Result = %lf", double(result)/(i>0?i:1));
    return 0;
}
