/*!
 * Программа lab_01_5_2
 * Назначена принимать расположение векторов и выводить 0,
 * если они не пересекаются, или 1, если они пересекаются
 */

#include <stdio.h>
#include <math.h>

#define EIGHT 8
#define ONE 1
#define TWO 2

/* Коды ошибок
 * 1 - ошибка на этапе ввода. Не всем переменным удалось присвоить значения.
 * 2 = ошибка на этапе выполнения функции crossing. Вектора заданы неверно.
 */

// Функция, указывающая на то, пересекаются ли заданные векторы
int crossing(float pax, float pay, float pbx, float pby,
    float pcx, float pcy, float pdx, float pdy)
{
    if ((pax != pbx || pay != pby) && (pcx != pdx || pcy != pdy))
    {
        double comp; // Переменная векторного произведения

        comp = (pbx - pax) * (pdy - pcy) - (pby - pay) * (pdx - pcx);
        printf("%f ", comp);

        // Проверка условия, одного ли знака вычисленные величины
        if (comp > ONE)
            return ONE; // Случай пересечения
        else
            return 0; // Случай непересечения
    }
    else
    {
        printf("Input error.");

        return TWO;
    }
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
        int lol = crossing(pointx1, pointy1, pointx2, pointy2, pointx3,
            pointy3, pointx4, pointy4);
        if (lol != TWO)
            printf("%d", lol);
        else
            return lol;
    }
    else
    {
        printf("Input error.");

        return ONE;
    }

    return 0;
}
