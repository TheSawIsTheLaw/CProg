/*!
 * Программа lab_01_5_1
 * Назначена печатать десятичную запись заданного натурального числа
 */
#include <stdio.h>

#define DIVIDER 10
#define ONE 1
#define ZERO 0

int fullout(long long int number) // Функция вывода десятичной записи числа
{
    int presvar; // Вспомогательная переменная вывода десятичного значения

    long long int quest, div; // Переменная quest - переменная для нахождения
                              // div, которая в свою очередь играет роль
                              // наибольшего делителя для заданного числа

    div = ONE;
    quest = number;
    while (quest > ZERO) // Цикл высчитывания наибольшего делителя для n
    {
        div = div * DIVIDER;
        quest = number / div;
    }
    div = div / DIVIDER; // "Откат" лишнего начисления

    presvar = number / div; // Нахождение самого первого десятичного числа
    printf("%d", presvar);
    div = div / DIVIDER;
    while (div != ZERO) // Цикл вывода последующих чисел
    {
        presvar = number / div;
        presvar = presvar % DIVIDER;
        div = div / DIVIDER;
        printf("%d", presvar);
    }
	
    return ZERO;
}

int main(void) // Точка входа в приложение
{
    long long int number; // Задаваемое натуральное число

    int rc; // "Показательная" переменная ошибок ввода

    rc = scanf("%I64d", &number);
    if (rc == ONE) // Проверка вводимого значения
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
