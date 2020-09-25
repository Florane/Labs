#include <iostream>
#include <math.h>

int main()
{
	double x0, x1, x2;
    double y0, y1, y2;

	printf_s("Enter coords of point 1: ");
	scanf_s("%lf%lf", &x0, &y0);
    printf_s("Enter coords of point 2: ");
	scanf_s("%lf%lf", &x1, &y1);
    printf_s("Enter coords of point 3: ");
	scanf_s("%lf%lf", &x2, &y2);

	double result = 0;
	result += sqrt(abs((x0-x1)*(x0-x1))+abs((y0-y1)*(y0-y1)));
    result += sqrt(abs((x1-x2)*(x1-x2))+abs((y1-y2)*(y1-y2)));
    result += sqrt(abs((x2-x0)*(x2-x0))+abs((y2-y0)*(y2-y0)));

	printf_s("Perimeter: %lf", result);
	return 0;
}
