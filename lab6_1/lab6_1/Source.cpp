#include <iostream>

int main()
{
	setlocale(LC_ALL,"russian");
	
    int number;
    printf_s("Введите число: ");
    scanf_s("%d", &number);
    switch (number)
    {
        //output special cases
        case 0: printf_s("Ноль"); break;
        case 10: printf_s("Десять"); break;
        case 11: printf_s("Одинадцать"); break;
        case 12: printf_s("Двенадцать"); break;
        case 13: printf_s("Тринадцать"); break;
        case 14: printf_s("Четырнадцать"); break;
        case 15: printf_s("Пятнадцать"); break;
        case 16: printf_s("Шестнадцать"); break;
        case 17: printf_s("Семнадцать"); break;
        case 18: printf_s("Восемнадцать"); break;
        case 19: printf_s("Девятнадцать"); break;
        default:
            switch (number/10)
            {
                //output tens
                case 2: printf_s("Двадцать "); break;
                case 3: printf_s("Тридцать "); break;
                case 4: printf_s("Сорок "); break;
                case 5: printf_s("Пятьдесят "); break;
                case 6: printf_s("Шестьдесят "); break;
                case 7: printf_s("Семьдесят "); break;
                case 8: printf_s("Восемьдесят "); break;
                case 9: printf_s("Девяноста "); break;
                case 0:
                default: break;
            }
            switch (number%10)
            {
                //output units
                case 1: printf_s("Один"); break;
                case 2: printf_s("Два"); break;
                case 3: printf_s("Три"); break;
                case 4: printf_s("Четыре"); break;
                case 5: printf_s("Пять"); break;
                case 6: printf_s("Шесть"); break;
                case 7: printf_s("Семь"); break;
                case 8: printf_s("Восемь"); break;
                case 9: printf_s("Девять"); break;
                case 0:
                default: break;
            }
            break;
    }
    printf_s("\n");
    return 0;
}
