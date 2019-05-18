/* Упорядочить исходный массив по возрастанию вставками */

/* Коды ошибок:
 * 1 - введено неправильное количество членов массива
 * 2 - передан неверный индекс в функцию insert
 * 3 - ошибка ввода, не всем переменным было присвоено значение */

#include <stdio.h>

#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3

// Функция для заполнения массива
int getmas(int mas[], const int number)
{
    int rc;
    for (int i = ZERO; i < number; i++)
    {
        rc = scanf("%d", &mas[i]);
        // Проверка факта присвоения
        if (rc != ONE)
        {
            return THREE;
        }
    }
    return ZERO;
}

// Функция вставки в массив значения
int insert(int mas[], const int num, const int sizes, const int ind)
{
    if (sizes < ZERO)
        return ONE;
    if (ind < ZERO || ind > sizes - ONE)
        return TWO;
    int pre = num, prepre;
    for (int i = ind; i < sizes; i++)
    {
        prepre = mas[i];
        mas[i] = pre;
        pre = prepre;
    }
    return ZERO;
}

// Функция сортировки массива методом вставок
int insertionsort(int mas[], const int number)
{
    if (number < ZERO)
        return ONE;
    int mem;
    for (int i = ZERO; i < number; i++)
    {
        for (int j = ZERO; j < i; j++)
        {
            while (mas[i] > mas[j])
                j++;
            mem = mas[i];
            for (int k = i; k < number - ONE; k++)
                mas[k] = mas[k + ONE];
            insert(mas, mem, number, j);
        }
    }
    return ZERO;
}

// Функция вывода массива
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
        int mas[number], error = ZERO;
        error = getmas(mas, number);
        if (error)
            return error;
        error = insertionsort(mas, number);
        if (error)
            return error;
        error = printmas(mas, number);
        if (error)
            return error;
    }
    else if (rc != ONE)
        return THREE;
    else
        return ONE;

    return 0;
}