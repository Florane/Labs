#pragma once

struct Size
{
    int x,y;
};

double mean(int* num,int size); // calctulates column's mean
int min(int* num,int size,bool returnPosition); // minimum in column

//nice output
int maxOutput(int num[SIZE][SIZE],Size size); // maximum in whole array
void spaceOutput(int input,int max); // print output with minimal reserved space

void outputTerminal(int num[SIZE][SIZE],Size size); //output to terminal
void outputToFile(int num[SIZE][SIZE],Size size); // output to file
void outputToBinary(int num[SIZE][SIZE],Size size); // output to binary file
void outputSelector(int num[SIZE][SIZE],Size size); //selector for output type

void body(int num[SIZE][SIZE],Size size); // main body

void inputManual(); // input manually
void inputFromFile(); // input from file
void inputFromBinary(); //input from binary file
void inputRandom(); //input random from begin to end
void inputFormula(); //input through preset formula
void selector(); // selector
