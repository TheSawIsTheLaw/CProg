/*!
 * Программа lab_01_5_3
 * Назначена вычислять значение суммы ряда с точностью eps,
 * выводить точное значение функции, а также абсолютную и относительную
 * ошибку вычисления
 */

#include <stdio.h>
#include <math.h>

#define TWO 2
#define ONE 1
#define LEET 1337

/* Коды ошибок
 * 1 - ошибка на этапе ввода. Не всем переменным удалось присвоить значения.
 * 1337 - ошибка на этапе выполнения функций. Заданы неверные значения.
 */

// Функция высчитывания суммы ряда с точностью eps
float row(float varx, float eps)
{
    if (eps < 0 || fabs(varx) >= 1)
        return LEET;

    float funcval, rowvar; // Переменные настоящего члена и суммы ряда

    float denominator, numenator; // Переменные числителя и знаменателя

    denominator = TWO;
    numenator = ONE;

    rowvar = ONE;

    funcval = varx * varx / denominator; // Первый добавляющийся член суммы

    // Суммирование с точностью eps
    while (fabs(funcval) < eps)
    {
        rowvar += funcval;
        denominator += TWO;
        numenator += TWO;
        funcval = funcval * varx * varx * numenator / denominator;
    }

    return rowvar;
}

// Вывод точного значения функции
float exactval(float varx)
{
    float exact;

    exact = sqrt(ONE - varx * varx);
    exact = ONE / exact;

    return exact;
}

// Вывод абсолютной и относительной ошибки вычислений
float bi(float funcs, float funcx)
{
    float absolute;

    absolute = fabs(funcx - funcs); // На самом деле модуль здесь не требуется

    return absolute;
}
float as(float absolute, float funcx)
{
    float relative;
    relative = fabs(absolute / funcx); // Оставил во имя возможности изменить
    // функцию, в которой возможно отрицательное значения

    return relative;
}

// Точка входа в приложение
int main(void)
{
    float varx, eps; // Переменная х и точность

    int rc; // Переменная проверки правильности ввода

    rc = scanf("%f%f", &varx, &eps);
    if (rc == TWO)
    {
        int funcs;
        float funcx;

        funcs = row(varx, eps);
        funcx = exactval(varx);

        float absolute, relative;
        absolute = bi(funcs, funcx);
        relative = as(absolute, funcx);
        if (funcs == LEET)
        {
            printf("Input error.");

            return LEET;
        }
        else
        {
            printf("%d %f %f %f", funcs, funcx, absolute, relative);
        }
    }
    else
    {
        printf("Input error.");

        return ONE;
    }

    return 0;
}
