/* Написать программу, которая запрашивает у пользователя элементы
 * целочисленного статического массива и выводит произведение нечетных
 * элементов массива;
 * Максимальное количество элементов, которое может ввести пользователь,
 * равно 10. */

/* Коды ошибок:
 * 1 - введено неправильное количество членов массива
 * 2 - нечётных элементов в введённом массиве нет
 * 3 - ошибка ввода, не всем переменным было присвоено значение */

#include <stdio.h>

#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define TEN 10

// Функция для заполнения массива
int getmas(int mas[], int const number)
{
    int rc;
    for (int i = ZERO; i < number; i++)
    {
        rc = scanf("%d", &mas[i]);
        if (rc != ONE)
        {
            return TWO;
        }
    }
    return ZERO;
}

// Функция, возвращающая произведение всех нечётных членов массива
// Если нечётных элементов нет, то возвращает код ошибки 2
int multodd(int const mas[], const int number)
{
    int mult = ONE, q = ZERO;
    // Переменные произведения нечётных элементов и наличия их в массиве
    for (int i = ZERO; i < number; i++)
    {
        if (mas[i] % TWO)
        {
            mult = mult * mas[i];
            q += ONE;
        }
    }
    if (q)
        return mult;
    else
        return TWO;
}

// Точка входа
int main(void)
{
    int number, rc;
    // Переменные количества членов массива и присвоенных значений
    rc = scanf("%d", &number);

    if (number <= TEN && number > ZERO && rc == ONE)
    {
        int mas[number], error = ZERO;
        error = getmas(mas, number);
        if (error)
            return error;
        int mult = multodd(mas, number);
        if (mult == TWO)
            return mult;
        else
            printf("%d", mult);
    }
    else if (rc != ONE)
        return THREE;
    else
        return ONE;

    return 0;
}