/*!
 * Программа lab_01_5_2
 * Назначена принимать расположение векторов и выводить 0,
 * если они не пересекаются, или 1, если они пересекаются
 */

#include <stdio.h>
#include <math.h>

#define EIGHT 8
#define ONE 1

// Функция, указывающая на то, пересекаются ли заданные векторы
int crossing(float pax, float pay, float pbx, float pby,
    float pcx, float pcy, float pdx, float pdy)
{
    double idcos1, idcos2; // Переменные значения углов от одного вектора
    // к другому

    idcos1 = (pcx - pax) * (pdx - pax) + (pcy - pay) *
        (pdy - pay); // Вычисление первого косинуса угла
    idcos1 = idcos1 / (sqrt((pcx - pax) * (pcx - pax) +
        (pcy - pay) * (pcy - pay)) * sqrt((pdx - pax) *
        (pdx - pax) + (pdy - pay) * (pdy - pay)));

    idcos2 = (pcx - pbx) * (pdx - pbx) + (pcy - pby) *
        (pdy - pby); // Вычисление второго косинуса угла
    idcos2 = idcos2 / (sqrt((pcx - pbx) * (pcx - pbx) +
        (pcy - pby) * (pcy - pby)) * sqrt((pdx - pbx) *
        (pdx - pbx) + (pdy - pby) * (pdy - pby)));

    // Проверка условия, одного ли знака вычисленные величины
    if ((idcos1 <= 0 && idcos2 >= 0) || (idcos1 >= 0 && idcos2 <= 0))
        printf("1"); // Случай пересечения
    else
        printf("0"); // Случай непересечения

    return 0;
}

// Точка входа в приложение
int main(void)
{
    float pointx1, pointy1, pointx2, pointy2, pointx3, pointy3,
        pointx4, pointy4; // Переменные координат векторов 12 и 34
    int rc; // Переменная проверки правильности ввода

    rc = scanf("%f %f %f %f %f %f %f %f", &pointx1, &pointy1, &pointx2,
        &pointy2, &pointx3, &pointy3, &pointx4, &pointy4);
    if (rc == EIGHT)
    {
        if (pointx1 != pointx2 && pointy1 != pointy2 && pointx3 != pointx4 &&
            pointy3 != pointy4)
            crossing(pointx1, pointy1, pointx2, pointy2, pointx3, pointy3,
                pointx4, pointy4);
        else
        {
            printf("Input error.");

            return ONE;
        }
    }
    else
    {
        printf("Input error.");

        return ONE;
    }

    return 0;
}
