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

/* Макрос для нахождения косинуса угла между векторами */
#define COSVEC(x1, y1, x2, y2, x3, y3)\
    (((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1))/(sqrt((x2 - x1) *\
    (x2 - x1) + (y2 - y1) * (y2 - y1)) * sqrt((x3 - x1) *(x3 - x1) + \
    (y3 - y1) * (y3 - y1))))

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
        double idcos1, idcos2, idcos3, idcos4; // Переменные значения углов от
        // одного вектора к другому

        idcos1 = COSVEC(pax, pay, pcx, pcy, pdx, pdy);
        // Вычисление первого косинуса угла

        idcos2 = COSVEC(pbx, pby, pcx, pcy, pdx, pdy);
        // Вычисление второго косинуса угла

        idcos3 = COSVEC(pdx, pdy, pbx, pby, pax, pay);
        // Вычисление третьего косинуса угла

        idcos4 = COSVEC(pcx, pcy, pbx, pby, pax, pay);
        // Вычисление четвёртого косинуса угла

        // Проверка условия, одного ли знака вычисленные величины
        if ((idcos1 * idcos2 <= 0 && idcos3 * idcos4 <= 0) || (idcos1 == 0 &&
            idcos2 == 0 && idcos3 == 0 && idcos4 == 0))
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
        if (lol != 2)
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
