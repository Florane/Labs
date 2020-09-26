#include <iostream>

int main()
{
    double result = 1;
    double entry = 1;
    do
    {
        result *= entry;
        printf_s("Enter number: ");
        scanf_s("%lf", &entry);  
    } while(entry != 0);
    printf_s("Result: %lf\n", result);
}
