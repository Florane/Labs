#include <iostream>
#include <conio.h>
#include <time.h>

#define SIZE 256

struct Size
{
    int x,y;
};

double mean(int* num,int size) // calctulates column's mean
{
    double sum = 0;
    for(int i = 0;i < size;i++)
        sum += num[i];
    return sum/size;
}

int min(int* num,int size,bool returnPosition) // minimum in column
{
    int result = num[0];
    int pos = 0;
    for(int i = 0;i < size;i++)
    {
        if(num[i] < result)
        {
            result = num[i];
            pos = i;
        }
    }
    if(returnPosition)
        return pos;
    return result;
}

int maxOutput(int num[SIZE][SIZE],Size size) // maximum in whole array
{
    int result = num[0][0];
    for(int a = 0;a < size.x;a++)
    {
        for(int b = 0;b < size.y;b++)
        {
            if(num[a][b] > result)
            {
                result = num[a][b];
            }
        }
    }
    return result;
}

void spaceOutput(int input,int max) // print output with minimal reserved space
{
    if(max < 10)
        printf_s("%1d ",input);
    else if(max < 100)
        printf_s("%2d ",input);
    else if(max < 1000)
        printf_s("%3d ",input);
    else if(max < 10000)
        printf_s("%4d ",input);
    else if(max < 100000)
        printf_s("%5d ",input);
    else if(max < 1000000)
        printf_s("%6d ",input);
    else
        printf_s("%d",input);
}

void outputTerminal(int num[SIZE][SIZE],Size size) //output to terminal
{
    int max = maxOutput(num,size);
    for(int b = 0;b < size.y;b++)
    {
        for(int a = 0;a < size.x;a++)
        {
            spaceOutput(num[a][b], max);
        }
        printf_s("\n");
    }
}

void outputToFile(int num[SIZE][SIZE],Size size) // output to file
{
    FILE* file;
    fopen_s(&file, "file.txt", "w");

    fprintf_s(file,"%d %d ",size.x,size.y);
    for(int b = 0;b < size.y;b++)
    {
        for(int a = 0;a < size.x;a++)
        {
            fprintf_s(file,"%d ",num[a][b]);
        }
    }
    fclose(file);
}

void outputToBinary(int num[SIZE][SIZE],Size size) // output to binary file
{
    FILE* file;
    fopen_s(&file, "file.bin", "wb");

    fwrite(&size,sizeof(Size),1,file);
    for(int a = 0;a < size.x;a++)
    {
        fwrite(num[a],sizeof(int),size.y,file);
    }
    fclose(file);
}

void outputSelector(int num[SIZE][SIZE],Size size) //selector for output type
{
    printf_s("Select: \n1: Output to terminal\n2: Save to file\n3: Save to binary\n");
    char c;
    do {
        c = _getch();
    } while(c<'1'||c>'3');

    switch(c)
    {
        case '1': outputTerminal(num,size); break;
        case '2': outputToFile(num,size); break;
        case '3': outputToBinary(num,size); break;
    }
}

void body(int num[SIZE][SIZE],Size size) // main body
{
    outputSelector(num,size);

    int mins[SIZE];
    // int* mins = (int*) malloc(size.x*sizeof(int));
    for(int i = 0;i < size.x;i++)
    {
        mins[i] = min(num[i],size.y,false);
    }

    int minPosition = min(mins,size.x,true);
    double result = mean(num[minPosition],size.y);
    printf_s("Result: %lf\n",result);
}

void inputManual() // input manually
{
    Size size;
    printf_s("Enter size x: ");
    scanf_s("%d",&size.x);
    printf_s("Enter size y: ");
    scanf_s("%d",&size.y);

    int num[SIZE][SIZE];
    // int** num = (int**) malloc(size.x*sizeof(int*));
    // for(int i = 0;i < size.x;i++)
    //     num[i] = (int*) malloc(size.y*sizeof(int));

    for(int a = 0;a < size.y;a++)
    {
        for(int b = 0;b < size.x;b++)
        {
            printf_s("Enter number in %d,%d: ",a,b);
            scanf_s("%d",&num[b][a]);
        }
    }
    body(num,size);
}

void inputFromFile() // input from file
{
    Size size;
    FILE* file;
    fopen_s(&file, "file.txt", "r");
    fscanf_s(file,"%d%d",&size.x,&size.y);

    int num[SIZE][SIZE];
    // int** num = (int**) malloc(size.x*sizeof(int*));
    // for(int i = 0;i < size.x;i++)
    //     num[i] = (int*) malloc(size.y*sizeof(int));

    for(int b = 0;b < size.y;b++)
    {
        for(int a = 0;a < size.x;a++)
        {
            fscanf_s(file,"%d",&num[a][b]);
        }
    }
    fclose(file);
    body(num,size);
}

void inputFromBinary() //input from binary file
{
    Size size;
    FILE* file;
    fopen_s(&file, "file.bin", "rb");
    fread_s(&size,sizeof(Size),sizeof(Size),1,file);

    int num[SIZE][SIZE];
    // int** num = (int**) malloc(size.x*sizeof(int*));
    // for(int i = 0;i < size.x;i++)
    //     num[i] = (int*) malloc(size.y*sizeof(int));

    for(int a = 0;a < size.x;a++)
    {
        fread_s(num[a],sizeof(int)*size.y,sizeof(int),size.y,file);
    }
    fclose(file);
    body(num,size);
}

void inputRandom() //input random from begin to end
{
    srand(time(0));
    Size size;
    printf_s("Enter size x: ");
    scanf_s("%d",&size.x);
    printf_s("Enter size y: ");
    scanf_s("%d",&size.y);

    int begin, end;
    printf_s("Enter begin: ");
    scanf_s("%d",&begin);
    printf_s("Enter end: ");
    scanf_s("%d",&end);

    int num[SIZE][SIZE];
    // int** num = (int**) malloc(size.x*sizeof(int*));
    // for(int i = 0;i < size.x;i++)
    //     num[i] = (int*) malloc(size.y*sizeof(int));

    for(int a = 0;a < size.x;a++)
    {
        for(int b = 0;b < size.y;b++)
        {
            num[a][b] = rand()%(end-begin+1)+begin;
        }
    }
    body(num,size);
}

void inputFormula() //input through preset formula
{
    Size size;
    printf_s("Enter size x: ");
    scanf_s("%d",&size.x);
    printf_s("Enter size y: ");
    scanf_s("%d",&size.y);

    int num[SIZE][SIZE];
    // int** num = (int**) malloc(size.x*sizeof(int*));
    // for(int i = 0;i < size.x;i++)
    //     num[i] = (int*) malloc(size.y*sizeof(int));

    for(int a = 0;a < size.x;a++)
    {
        for(int b = 0;b < size.y;b++)
        {
            if(a>b)
                num[a][b] = a+b+2;
            else
                num[a][b] = (a+1)*(b+1);
        }
    }
    body(num,size);
}

int main() //main selector
{
    printf_s("Select: \n1: Enter manually\n2: Enter from file\n3: Enter from binary file\n4: Enter random\n5: Enter from formula\n");
    char c;
    do {
        c = _getch();
    } while(c<'1'||c>'5');

    switch(c)
    {
        case '1': inputManual(); break;
        case '2': inputFromFile(); break;
        case '3': inputFromBinary(); break;
        case '4': inputRandom(); break;
        case '5': inputFormula(); break;
    }

    return 0;
}
