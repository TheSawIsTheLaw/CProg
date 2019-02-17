/*!
 * Программа lab_01_2_1
 * Назначена выводить периметр заданного по трём точкам треугольника.
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    int A1, A2, B1, B2, C1, C2; /*!< Координаты точек треугольника */

    float Perimeter; /*!< Значение периметра заданного треугольника */

    /*!
     * Ввод значений переменных A1, A2, B1, B2, C1, C2 пользователем
     */
    printf("Please, input point A coordinates (separated by space): ");
    scanf("%d %d", &A1, &A2);
    printf("Please, input point B coordinates (separated by space): ");
    scanf("%d %d", &B1, &B2);
    printf("Please, input point C coordinates (separated by space): ");
    scanf("%d %d", &C1, &C2);

    /*!
     * Вывод значения периметра заданного треугольника
     */
    Perimeter = sqrt((B1-A1)*(B1-A1)+(B2-A2)*(B2-A2)) + sqrt((C1-B1)*(C1-B1)+(C2-B2)*
    (C2-B2)) + sqrt((A1-C1)*(A1-C1)+(A2-C2)*(A2-C2));
    printf("Perimeter of triangle = %.5f", Perimeter);

    return 0;
}
