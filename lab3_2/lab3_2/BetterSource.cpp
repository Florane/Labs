#include <iostream>
#include <math.h>

int main()
{
	double x[3], y[3];
	for(int i=0;i<3;i++)
	{
		printf_s("Enter coords of point %d: ",i+1);
		scanf_s("%lf%lf", &x[i], &y[i]);
	}
	double result = 0;
	for(int i=0;i<3;i++)
	{
		result += sqrt(abs((x[i]-x[(i+1)%3])*(x[i]-x[(i+1)%3]))+abs((y[i]-y[(i+1)%3])*(y[i]-y[(i+1)%3])));
	}
	printf_s("Perimeter: %lf", result);
	return 0;
}
