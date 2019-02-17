/*!
 * Программа lab_01_2_3
 * Назначена выводить общее сопротивление параллельно соединённых резисторов
 */
#include <stdio.h>

int main(void)
{
    int res1, res2, res3; /*!< Сопротивление каждого резистора */

    float res; /*!< Общее сопротивление */

    /*!
     * Ввод значений переменных res1, res2, res3 пользователем
     */
    printf("Input R1: ");
    scanf("%d", &res1);
    printf("Input R2: ");
    scanf("%d", &res2);
    printf("Input R3: ");
    scanf("%d", &res3);

    /*!
     * Расчёт общего сопротивления по формуле и вывод значения общего
     * сопротивления
     */
    res = (1/res1 + 1/res2 + 1/res3);
    res = 1 / res;
    printf("Total resistance = %.5f", res);

    return 0;
}
