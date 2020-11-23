#include <iostream>
#include <conio.h>

#define SIZE 85

struct Student
{
    int grade[3];
};

double mean(Student student) //calculates mean grade
{
    return (student.grade[0]+student.grade[1]+student.grade[2])/3.0;
}

void outputToBinary(Student* num,int size) // output to binary file
{
    FILE* file;
    fopen_s(&file, "file.bin", "wb");

    fwrite(&size,sizeof(int),1,file);
    fwrite(num,sizeof(Student),size,file);

    fclose(file);
    printf_s("Done\n");
}

void body(Student* num,int size) // calculate biggest mean grade
{
    double max = -1;int pos;
    for(int i = 0;i < size;i++)
    {
        if(mean(num[i]) > max)
        {
            pos = i;
            max = mean(num[i]);
        }
    }
    printf_s("Student %d has the biggest mean grade: %lf\n",pos+1,max);
}

void inputManual() // input manually
{
    int size;
    printf_s("Enter a count of students: ");
    scanf_s("%d",&size);

    Student num[SIZE];
    // Student* num = (Student*) malloc(size*sizeof(Student));
    for(int i = 0;i < size;i++)
    {
        printf_s("Enter 3 grades for student %d: ",i+1);
        scanf_s("%d%d%d",&num[i].grade[0],&num[i].grade[1],&num[i].grade[2]);
    }

    printf_s("Save? (y/n)"); // save to binary file selector
    char c;
    do {
        c = _getch();
    } while(c!='y' && c!='n');
    printf_s("\n");
    switch (c)
    {
    	case 'n': break;
    	case 'y': outputToBinary(num,size); break;
    }

    body(num,size);
}

void inputFromFile() // input from text file
{
    FILE* file;
    fopen_s(&file, "file.txt", "r");

    Student num[SIZE]; int i = 0, test;
    while(!feof(file))
    {
        Student buffer;
        test = fscanf_s(file,"%d%d%d",&buffer.grade[0],&buffer.grade[1],&buffer.grade[2]);
        if(test != EOF)
        {
            num[i] = buffer;
            i++;
        }
    }
    fclose(file);
    body(&num[0],i);
}

void inputFromBinary() // input from binary file
{
    FILE* file;
    fopen_s(&file, "file.bin", "rb");

    int size;
    fread_s(&size,sizeof(int),sizeof(int),1,file);

    Student num[SIZE];
    fread_s(num,sizeof(Student)*85,sizeof(Student),size,file);

    body(&num[0],size);
}

int main() // selector
{
    printf_s("Select: \n1: Enter manually\n2: Enter from file\n3: Enter from binary file\n");
    char c;
    do {
        c = _getch();
    } while(c<'1'||c>'3');

    switch(c)
    {
        case '1': inputManual(); break;
        case '2': inputFromFile(); break;
        case '3': inputFromBinary(); break;
    }

    return 0;
}
