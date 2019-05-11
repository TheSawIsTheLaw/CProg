/* Сформировать новый массив из элементов исходного массива. При этом в новый
 * массив помещаются (копируются) элементы исходного массива, которые
 * являются простыми числами */

/* Коды ошибок:
 * -2 - ошибка в функции findprime, передано неверное количество членов массива
 * -1 - в заданном массиве нет простых чисел
 * 1 - введено неправильное количество членов массива
 * 3 - ошибка ввода, не всем переменным было присвоено значение */

#include <stdio.h>

#define NTWO -2
#define NONE -1
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3

// Функция для заполнения массива, возвращает 2, если передано неверное
// количество членов, 3, если значение не было присвоено
int getmas(int mas[], const int number)
{
    if (number < ZERO)
        return TWO;
    int rc; // Переменная проверки присвоения значения
    for (int i = ZERO; i < number; i++)
    {
        rc = scanf("%d", &mas[i]);
        if (rc != ONE)
        {
            return THREE;
        }
    }
    return ZERO;
}

// Функция проверки, является ли число простым (1 - да, 0 - нет)
int isprime(const int num)
{
    if (num != ONE && num > ZERO)
    {
        int i = TWO;
        while (num % i > ZERO)
            i++;
        if (num == i)
            return ONE;
        else
            return ZERO;
    }
    return ZERO;
}

// Функция нахождения в массиве простых чисел и перенесения их в другой массив.
// В случае отсутствия в массиве простых чисел возвращает -1;
// В случае, когда передано неверное количество элементов массива возвращает -2;
// В случае, когда всё верно, возвращает количество простых чисел
int findprime(int const mas[], const int number, int masb[])
{
    if (number < ZERO)
        return NTWO;
    int j = ZERO;
    for (int i = ZERO; i < number; i++)
    {
        if (isprime(mas[i]))
        {
            masb[j] = mas[i];
            j += ONE;
        }
    }
    if (j)
        return j;
    else
        return NONE;
}

// Функция вывода массива, если передано неверное кол-во членов массива
// возвращает 1, иначе возвращает 0
int printmas(int const mas[], const int number)
{
    if (number < ZERO)
        return ONE;
    for (int i = ZERO; i < number; i++)
        printf("%d ", mas[i]);
    return ZERO;
}

// Точка входа
int main(void)
{
    int number, rc;
    // Переменные количества членов массива и присвоенных значений
    rc = scanf("%d", &number);

    if (rc && number > ZERO)
    {
        int mas[number], masb[number], error = ZERO;
        // Два рабочих массива и переменная ошибок
        error = getmas(mas, number);
        if (error)
            return error;
        error = findprime(mas, number, masb);
        if (error < ZERO)
            return error;
        error = printmas(masb, error);
        if (error)
            return ONE;
    }
    else if (rc != ONE)
        return THREE;
    else
        return ONE;

    return 0;
}