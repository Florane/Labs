#include <iostream>
#include <conio.h>
#include <time.h>
#include <math.h>

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
        int buffer = num[i];
        num[i] = num[i+1];
        num[i+1] = buffer;
    }
    printf_s("Result(2):");
    for(int i = 0;i < size;i++)
        printf_s(" %d",num[i]);
    printf_s("\n");
}

void manual(int size)
{
    printf_s("Enter %d numbers: ", size);
    int* num = (int*) malloc(size*sizeof(int));
    for(int i = 0;i < size;i++)
    {
        scanf_s("%d",&num[i]);
    }
    result(num,size);
}

void random(int size)
{
    int* num = (int*) malloc(size*sizeof(int));
    int A, B;
    printf_s("Enter begin: ");
    scanf_s("%d",&A);
    printf_s("Enter end: ");
    scanf_s("%d",&B);

    for(int i = 0;i < size;i++)
    {
        num[i] = rand()%(B-A+1)+A;
    }
    result(num,size);
}

int main()
{
    srand(time(0));
    int size;
    printf_s("Enter size: ");
    scanf_s("%d",&size);

    char c;
    printf_s("Select: \n1: Enter manually\n2: Enter random\n");
    do {
        c = _getch();
        printf_s("%c",c);
    } while(c!='1'&&c!='2');

    switch (c)
    {
        case '1': manual(size); break;
        case '2': random(size); break;
    }
}
