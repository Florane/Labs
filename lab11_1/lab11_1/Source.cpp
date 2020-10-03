#include <iostream>

int main()
{
    int n; double x;
    printf_s("Enter n: ");
    scanf_s("%d", &n);
    printf_s("Enter x: ");
    scanf_s("%lf", &x);

    double result = 0;
    for(int i = 0;i < n;i++)
    {
        double step = i%2==0 ? -1 : 1;
        step *= 2*x;
        printf_s("%d: %lf\n",i,step);
        result += step;
    }
    printf_s("Result: %lf\n",result);
    return 0;
}
