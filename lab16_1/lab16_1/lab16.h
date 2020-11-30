#pragma once

struct Student
{
    int grade[3];
};

double mean(Student student); //calculates mean grade
void outputToBinary(Student* num,int size); // output to binary file
void body(Student* num,int size); // calculate biggest mean grade
void inputManual(); // input manually
void inputFromFile(); // input from text file
void inputFromBinary(); // input from binary file
void selector(); //selector
