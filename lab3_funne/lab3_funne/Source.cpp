#include <iostream>
#define SELECT_TASK 0

int main()
{
    double a, b;
    printf_s("Enter a: ");
    scanf_s("%lf", &a);
#if SELECT_TASK == 0
//a
    a *= a;//2
    a *= a;//4
#elif SELECT_TASK == 1
//b
    b = a * a;//2
    b *= a;//3
    b *= b;//6
    b *= b;//12
    b *= a;//13
#elif SELECT_TASK == 2
//c
    a *= a * a;//3
    a *= a;//6
#elif SELECT_TASK == 3
//d

#elif SELECT_TASK == 4
//e
#elif SELECT_TASK == 5
//f
#endif
    return 0;
}
