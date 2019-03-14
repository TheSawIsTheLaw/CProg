/*!
 * Программа lab_01_5_1
 * Назначена печатать десятичную запись заданного натурального числа
 */
#include <stdio.h>

#define DIVIDER 10
#define ONE 1
#define ZERO 0

// Функция вывода десятичной записи числа
int fullout(long long int number)
{
    long long int quest;
    unsigned long long int presvar, div;
    int i;
    // Переменная quest - переменная для нахождения div, которая в свою очередь
    // играет роль наибольшего делителя для заданного числа
    // presvar - переменная вывода настоящего значения

    div = ONE;
    quest = number;
    // Цикл высчитывания наибольшего делителя для number
    while (quest > ZERO)
    {
        div = div * DIVIDER;
        quest = number / div;
    }
    div = div / DIVIDER; // "Откат" лишнего начисления

    presvar = number / div; // Нахождение самого первого десятичного числа
    i = presvar;
    printf("%d", i);
    div = div / DIVIDER;
    // Цикл вывода последующих чисел
    while (div != ZERO)
    {
        presvar = number / div;
        presvar = presvar % DIVIDER;
        div = div / DIVIDER;
        i = presvar;
        printf("%d", i);
    }
	
    return ZERO;
}

// Точка входа в приложение
int main(void)
{
    long long int number; // Задаваемое натуральное число

    int rc; // "Показательная" переменная ошибок ввода

    rc = scanf("%I64d", &number);
    // Проверка вводимого значения
    if (rc == ONE)
    {
        if (number > ZERO)
            fullout(number);
        else
        {
            printf("Negative number or 0.");
			
            return ONE;
        }
    }
    else
    {
        printf("Input error.");
		
        return ONE;
    }

    return ZERO;
}
