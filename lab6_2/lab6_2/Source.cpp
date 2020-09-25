#include <iostream>

double max(double a, double b)
{
    return a>b ? a : b;
}

int main()
{
    double r0,r1,r2,r3,r4;

    printf_s("Enter radiuses of 5 circles: ");
    scanf_s("%lf%lf%lf%lf%lf",&r0,&r1,&r2,&r3,&r4);

    printf_s("Result: %lf",max(r0,max(r1,max(r2,max(r3,r4)))));
}
