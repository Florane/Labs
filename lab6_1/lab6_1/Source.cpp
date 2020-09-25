#include <iostream>

int main()
{
    int number;
    printf_s("Enter Number: ");
    scanf_s("%d", &number);
    switch (number)
    {
        //output special cases
        case 0: printf_s("Zero"); break;
        case 10: printf_s("Ten"); break;
        case 11: printf_s("Eleven"); break;
        case 12: printf_s("Twelve"); break;
        case 13: printf_s("Thirteen"); break;
        case 14: printf_s("Fourteen"); break;
        case 15: printf_s("Fifteen"); break;
        case 16: printf_s("Sixteen"); break;
        case 17: printf_s("Seventeen"); break;
        case 18: printf_s("Eightteen"); break;
        case 19: printf_s("Nineteen"); break;
        default:
            switch (number/10)
            {
                //output tens
                case 2: printf_s("Twenty "); break;
                case 3: printf_s("Thirty "); break;
                case 4: printf_s("Fourty "); break;
                case 5: printf_s("Fifty "); break;
                case 6: printf_s("Sixty "); break;
                case 7: printf_s("Seventy "); break;
                case 8: printf_s("Eighty "); break;
                case 9: printf_s("Ninety "); break;
                case 0:
                default: break;
            }
            switch (number%10)
            {
                //output units
                case 1: printf_s("One"); break;
                case 2: printf_s("Two"); break;
                case 3: printf_s("Three"); break;
                case 4: printf_s("Four"); break;
                case 5: printf_s("Five"); break;
                case 6: printf_s("Six"); break;
                case 7: printf_s("Seven"); break;
                case 8: printf_s("Eight"); break;
                case 9: printf_s("Nine"); break;
                case 0:
                default: break;
            }
            break;
    }
    printf_s("\n");
}
