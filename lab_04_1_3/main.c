/* Вставить в исходный массив после каждого элемента, кратного трем, очередное число
* Фибоначчи (первое число Фибоначчи равно 0, второе – 1) */

/* Коды ошибок:
 * -1 - передано неверное количество членов в функцию вставки
 * 1 - введено неправильное количество членов массива
 * 2 - в заданном массиве нет чисел, кратных трёх
 * 3 - ошибка ввода, не всем переменным было присвоено значение */

#include <stdio.h>

#define NONE -1
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define THOU 1000

// Маскрос для проверки кратности трём
#define ISMULTOF(a) (a % THREE)

// Функция для заполнения массива, возвращает 3 в случае неприсвоения
// (см. Коды ошибок), 0 - когда всё прошло успешно
int getmas(int mas[], const int number)
{
    if (number < ZERO)
        return ONE;
    int rc; // Переменная проверки присвоения значения
    for (int i = ZERO; i < number; i++)
    {
        rc = scanf("%d", &mas[i]);
        if (rc != ONE)
            return THREE;
    }
    return ZERO;
}

// Фунция вставки в массив значения, возвращает -1, если размер массива задан
// неверно, иначе - новый размер массива
int insert(int mas[], const int num, const int sizes, const int ind)
{
    if (sizes < ZERO)
        return NONE;
    int pre = num, size = sizes, prepre;
    // prepre - переменная для смещения значений
    // Остальные переменные для того, чтобы не портить консты
    size += ONE;
    for (int i = ind; i < size; i++)
    {
        prepre = mas[i];
        mas[i] = pre;
        pre = prepre;
    }
    return size;
}

// Функция, вставляющая восле чисел, кратных трём, последовательные числа
// Фибоначчи
int insfib(int mas[], int number)
{
    int amount = ZERO; // Переменная количества произведённых вставок
    int preprefib = ZERO, prefib = ONE, fib = ONE;
    //  Переменные для последовательных чисел Фибоначчи
    int i = ZERO; // Вспомогательная переменная
    while (i < number)
    {
        if (ISMULTOF(mas[i]) == ZERO)
        {
            if (amount == ZERO)
            {
                number = insert(mas, preprefib, number, i + ONE);
                if (number < ZERO)
                    return NONE;
                i += TWO;
            }
            else if (amount == ONE)
            {
                number = insert(mas, prefib, number, i + ONE);
                if (number < 0)
                    return NONE;
                i += TWO;
            }
            else
            {
                number = insert(mas, fib, number, i + ONE);
                if (number < ZERO)
                    return NONE;
                preprefib = prefib;
                prefib = fib;
                fib = prefib + preprefib;
                i += TWO;
            }
            amount++;
        }
        else
            i++;
    }
    return amount;
}

// Функция вывода массива, возвращает 1, когда передано неверное количество
// элементов
int printmas(int mas[], const int number)
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
        int mas[THOU], error = ZERO;
        error = getmas(mas, number);
        if (error)
            return error;
        error = insfib(mas, number);
        if (error == NONE)
            return TWO;
        number += error;
        error = printmas(mas, number);
        if (error)
            return TWO;
    }
    else if (rc != ONE)
        return THREE;
    else
        return ONE;

    return 0;
}