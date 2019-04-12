/*!
 * Программа lab_01_5_1
 * Назначена печатать десятичную запись заданного натурального числа
 */
#include <stdio.h>

#define DIVIDER 10
#define ONE 1
#define ZERO 0
#define TWO 2

/* Коды ошибок
 * 1 - ошибка на этапе ввода. Не всем переменным удалось присвоить значения.
 * 2 - ошибка на этапе работы функции fullout. Переданное ей значение меньше
 * или равно нулю.
 */

// Функция вывода десятичной записи числа
int fullout(int number)
{
    if (number <= ZERO)
    {
        printf("Negative number or 0.");
        return TWO;
    }

    long long int quest, presvar, div;
    int i;
    // Переменная quest - переменная для нахождения div, которая в свою очередь
    // играет роль наибольшего делителя для заданного числа
    // presvar - переменная вывода настоящего значения
    // i - переменная вывода десятичного числа

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
    div = div / DIVIDER;
    // Цикл вывода последующих чисел
    while (div != ZERO)
    {
        printf("%d", i);
        presvar = number / div;
        presvar = presvar % DIVIDER;
        div = div / DIVIDER;
        i = presvar;
    }
    printf("%d", i);
    return 0;
}

// Точка входа в приложение
int main(void)
{
    int number; // Задаваемое натуральное число

    int rc, q; // "Показательные" переменные ошибок ввода и функции fullout

    rc = scanf("%d", &number);
    // Проверка вводимого значения
    if (rc == ONE)
    {
        q = fullout(number);
    }
    else
    {
        printf("Input error.");
		
        return ONE;
    }
    if (q == ZERO)
        return 0;
    else
        return q;
}
