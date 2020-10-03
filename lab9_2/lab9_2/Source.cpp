#include <iostream>
#include <math.h>

int main()
{
    double a,b,c;
    printf_s("Enter begin: ");
    scanf_s("%lf", &a);
    printf_s("Enter end: ");
    scanf_s("%lf", &b);
    printf_s("Enter step: ");
    scanf_s("%lf", &c);

    for(;a<=b;a+=c)
    {
        double result;
        if(a<0) {result = a*a*a*a;}
        else if(a <= 10) {result = 5*sin(a);}
        else if(a > 10) {result = 1/tan(a);}
        printf_s("Result on %lf: %lf\n",a,result);
    }
    return 0;
}
