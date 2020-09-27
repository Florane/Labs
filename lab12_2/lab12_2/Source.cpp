#include <iostream>

int main()
{
    int first = 1, second = 1, buffer;
    for(int i = 2;i < 15;i++)
    {
        buffer = first+second;
        first = second;
        second = buffer;
    }
    printf_s("Result: %d\n",second*100);
}
