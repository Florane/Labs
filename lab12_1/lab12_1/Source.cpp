#include <iostream>

int recursive(int step)
{
    printf_s("%d ",step);
    if(step==1 || step==2)
        return 1;
    return recursive(step-1)+recursive(step-2);
}

int main()
{
    int result = recursive(15)*100;
    printf_s("\nResult: %d\n",result);
    return 0;
}
