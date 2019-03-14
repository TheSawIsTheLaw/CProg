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

// Функция высчитывания суммы ряда с точностью eps
float row(float varx, float eps)
{
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
int bias(float funcs, float funcx)
{
    float absolute, relative;

    absolute = fabs(funcx - funcs); // На самом деле модуль здесь не требуется
    relative = fabs(absolute / funcx); // Оставил во имя возможности изменить
    // функцию, в которой возможно отрицательное значения

    printf("%f %f", absolute, relative);

    return 0;
}

// Точка входа в приложение
int main(void)
{
    float varx, eps; // Переменные точки, в кот. вычисляется значение и
    // "точности"

    int rc; // Переменная проверки правильности ввода

    rc = scanf("%f%f", &varx, &eps);
    if (rc == TWO)
    {
        float funcs, funcx;

        funcs = row(varx, eps);
        funcx = exactval(varx);
        printf("%f %f ", funcs, funcx);

        bias(funcs, funcx);
    }
    else
    {
        printf("Input error.");

        return ONE;
    }

    return 0;
}
