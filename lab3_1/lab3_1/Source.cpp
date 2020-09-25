#include <iostream>

int main()
{
	double chair, armchair, table;
	printf_s("Enter chair, armchair, and table cost: ");
	scanf_s("%lf%lf%lf", &chair, &armchair, &table);
	printf_s("Total cost: %lf\n", 4*chair+2*armchair+table);
}