#include <iostream>
#include <math.h>

int main()
{
    double x;
    printf_s("Enter x: ");
    scanf_s("%lf",&x);
    printf_s("Result: %lf", (2.0*(x*x+3))/(x*x-2*x+5));
    return 0;
}
