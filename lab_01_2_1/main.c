/*!
 * Программа lab_01_2_1
 * Назначена выводить периметр заданного по трём точкам треугольника.
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    int pointA1, pointA2, pointB1, pointB2, pointC1, pointC2; /*!< Точки */
    float Perimeter; /*!< Значение периметра заданного треугольника */

    /*!
     * Ввод значений переменных A1, A2, B1, B2, C1, C2 пользователем
     */
    printf("Please, input point A coordinates (separated by space): ");
    scanf("%d %d", &pointA1, &pointA2);
    printf("Please, input point B coordinates (separated by space): ");
    scanf("%d %d", &pointB1, &pointB2);
    printf("Please, input point C coordinates (separated by space): ");
    scanf("%d %d", &pointC1, &pointC2);

    /*!
     * Вывод значения периметра заданного треугольника
     */
    Perimeter = sqrt((pointB1-pointA1)*(pointB1-pointA1)+(pointB2-pointA2)*
	(pointB2-pointA2)) + sqrt((pointC1-pointB1)*(pointC1-pointB1)+
	(pointC2-pointB2)*(pointC2-pointB2)) + sqrt((pointA1-pointC1)*
	(pointA1-pointC1)+(pointA2-pointC2)*(pointA2-pointC2));
    printf("Perimeter of triangle = %.5f", Perimeter);

    return 0;
}
