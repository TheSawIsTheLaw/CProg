/*!
 * Программа lab_01_2_1
 * Назначена выводить периметр заданного по трём точкам треугольника.
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    float pointa1, pointa2, pointb1, pointb2, pointc1, pointc2; /*!< Точки */
    float perimeter; /*!< Значение периметра заданного треугольника */

    /*!
     * Ввод значений переменных pointa1, pointa2, pointb1, pointb2,
	 * pointc1, pointc2 пользователем
     */
    printf("Please, input point A coordinates (separated by space): ");
    scanf("%f %f", &pointa1, &pointa2);
    printf("Please, input point B coordinates (separated by space): ");
    scanf("%f %f", &pointb1, &pointb2);
    printf("Please, input point C coordinates (separated by space): ");
    scanf("%f %f", &pointc1, &pointc2);
	

    /*!
     * Вывод значения периметра заданного треугольника
     */
    perimeter = sqrt((pointb1 - pointa1) * (pointb1 - pointa1) + (pointb2 -
	pointa2) * (pointb2 - pointa2)) + sqrt((pointc1 - pointa1) * (pointc1 -
	pointa1) + (pointc2 - pointa2) * (pointc2 - pointa2)) + sqrt((pointc1 -
	pointb1) * (pointc1 - pointb1) + (pointc2 - pointb2) * (pointc2 -
	pointb2));
    printf("Perimeter of triangle = %.5f", perimeter);

    return 0;
}