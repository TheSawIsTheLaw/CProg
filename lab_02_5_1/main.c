/*!
 * Программа lab_01_5_1
 * Назначена печатать десятичную запись заданного натурального числа
 */
#include <stdio.h>

#define DIVIDER 10
#define ONE 1

int fullout(long long int n) // Функция вывода десятичной записи числа
{
    int presvar; // Вспомогательная переменная вывода десятичного значения

    long long int quest, div; // Переменная quest - переменная для нахождения
                              // div, которая в свою очередь играет роль
                              // наибольшего делителя для заданного числа

    div = ONE;
    quest = n;
    while (quest > 0) // Цикл высчитывания наибольшего делителя для n
    {
        div = div * DIVIDER;
        quest = n / div;
    }
    div = div / DIVIDER; // "Откат" лишнего начисления

    presvar = n / div; // Нахождение самого первого десятичного числа
    printf("%d", presvar);
    div = div / DIVIDER;
    while (div != 0) // Цикл вывода последующих чисел
    {
        presvar = n / div;
        presvar = presvar % DIVIDER;
        div = div / DIVIDER;
        printf("%d", presvar);
    }
	
    return 0;
}


int main(void) // Точка входа в приложение
{
    long long int n; // Задаваемое натуральное число

    int rc; // "Показательная" переменная ошибок ввода

    rc = scanf("%I64d", &n);
    if (rc == ONE) // Проверка вводимого значения
        if (n > 0)
            fullout(n);
        else
        {
            printf("Negative number or 0.");
			
            return ONE;
        }
    else
    {
        printf("Input error.");
		
        return ONE;
    }
	
    return 0;
}
