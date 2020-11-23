#include <iostream>
#include <conio.h>
#include <time.h>
#include <math.h>

#define SIZE 256

void outputFile(int* num, int size) // output to file
{
    FILE* file;
    fopen_s(&file,"log.txt","w");
	for(int i = 0;i < size;i++)
	{
		fprintf_s(file,"%d ", num[i]);
	}
    fclose(file);
}

void body(int* num, int size) // calculate geometric mean
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

    printf_s("Output to file \"log.txt\"? y/n");
    char c;
    do {
        c = _getch();
    } while(c!='y' && c!='n');
    switch (c)
    {
    	case 'n': break;
    	case 'y': outputFile(num,size); break;
    }
    printf("Done\n");
}

void inputManual(int size) // input manually
{
    printf_s("Enter %d numbers: ", size);
    int num[SIZE];
    // int* num = (int*) malloc(size*sizeof(int));
    for(int i = 0;i < size;i++)
    {
        scanf_s("%d",&num[i]);
    }
    body(num,size);
}

void inputRandom(int size) //input random from A to B
{
    int num[SIZE];
    // int* num = (int*) malloc(size*sizeof(int));
    int A, B;
    printf_s("Enter begin: ");
    scanf_s("%d",&A);
    printf_s("Enter end: ");
    scanf_s("%d",&B);

    for(int i = 0;i < size;i++)
    {
        num[i] = rand()%(B-A+1)+A;
    }
    body(num,size);
}

void inputFromFile() // input from file
{
    FILE* file;
    fopen_s(&file, "file.txt", "r");
	int num[SIZE]; int i = 0, test;
	while(!feof(file))
	{
		int buffer;
		test = fscanf_s(file,"%d",&buffer);
		if(test != EOF)
		{
		    num[i] = buffer;
		    i++;
		}
	}
    fclose(file);
	body(&num[0],i);
}

int main() // selector
{
    srand(time(0));
    int size;

    printf_s("Select: \n1: Enter manually\n2: Enter random\n3: Enter from file\n");
    char c;
    do {
        c = _getch();
    } while(c<'1'||c>'3');

    if(c == '3')
        inputFromFile();
    else
    {
    	printf_s("Enter size: ");
        scanf_s("%d",&size);
        if(c == '1')
            inputManual(size);
        else
            inputRandom(size);
    }
    return 0;
}
