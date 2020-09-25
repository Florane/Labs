#include <iostream>

int main()
{
    int grams;
    printf_s("Enter gramms: ");
    scanf_s("%d",&grams);
    printf_s("Tonns: %d\n",grams/(1000*1000));
    printf_s("Kilos: %d\n",grams/1000);
    return 0;
}
