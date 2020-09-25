#include <iostream>
#include <math.h>

int main()
{
    double x;
    printf_s("Enter x: ");
    scanf_s("%lf", &x);
    double result;

    if (x < 0) { result = (x *= x) * x; }
    if (x >= 0 && x <= 10) { result = 5 * sin(x); }
    if (x > 10) { result = 1 / tan(x); }

    printf_s("Result: %lf\n", result);
}
