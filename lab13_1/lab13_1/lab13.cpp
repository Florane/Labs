#include <math.h>

#include "lab13.h"

void result(int* num, int size)
{
    printf_s("Start:");
    for(int i = 0;i < size;i++)
        printf_s(" %d",num[i]);
    printf_s("\n");

    double result = 1;
    for(int i = 0;i < size;i++)
    {
        result *= num[i];
    }
    result = pow(result,1.0/size);
    printf_s("Result(1): %lf\n",result);

    for(int i = 0;i < size-1;i+=2)
    {
        num[i] = num[i]^num[i+1];
        num[i+1] = num[i+1]^num[i];
        num[i] = num[i]^num[i+1];
    }
    printf_s("Result(2):");
    for(int i = 0;i < size;i++)
        printf_s(" %d",num[i]);
    printf_s("\n");
}
