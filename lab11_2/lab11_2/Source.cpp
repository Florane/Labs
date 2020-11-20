#include <iostream>
#include <math.h>

double pow(int a, int b)
{
    double result = 1;
    for(int i = 0;i < b;i++)
    {
        result*=a;
    }
    return result;
}

double factorial(int n)
{
    double result = 1;
    for(int i = 1;i <= n;i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int x; double e;
    printf_s("Enter x: ");
    scanf_s("%d",&x);
    printf_s("Enter approx: ");
    scanf_s("%lf",&e);

    double result = 0;
    double step = e+1;
    for(int i = 0;fabs(step)>e;i++) // math.h needed here
    {
        step = i%2==0 ? -1 : 1;
        step *= (factorial(x+1))/(pow(i+1,i+1));
        printf_s("%d: %lf\n",i,step);
        result += step;
    }
    printf_s("Result: %lf\n",result);
    return 0;
}
