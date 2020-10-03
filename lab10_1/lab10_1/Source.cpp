#include <iostream>

double pow(int a, int b)
{
    double result = 1;
    for(int i = 0;i < b;i++)
    {
        result*=a;
    }
    return result;
}

int main()
{
    int number;
    printf_s("Enter number: ");
    scanf_s("%d", &number);

    double result = 0;
    for(int i = 0;i < number;i++)
    {
        for(int ia = 0;ia < number;ia++)
        {
            result += pow(i+1,ia+1);
        }
    }
    printf_s("Result: %lf\n", result);
    return 0;
}
