#include <iostream>

int main()
{
    int result;
    int start;

    printf_s("Enter a 5 digit number: ");
    scanf_s("%d", &start);
    result = start%10*10000+start/10%10*1000+start/100%10*100+start/1000%10*10+start/10000;

    printf_s("Result: %d\n",result);
}
