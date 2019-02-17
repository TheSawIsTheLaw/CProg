/*!
 * Программа lab_01_2_3
 * Назначена выводить общее сопротивление параллельно соединённых резисторов
 */
#include <stdio.h>

int main(void)
{
    int res1, res2, res3; /*!< Сопротивление каждого резистора */

    float Res; /*!< Общее сопротивление */

    /*!
     * Ввод значений переменных R1, R2, R3 пользователем
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
    Res = (1/res1 + 1/res2 + 1/res3);
    Res = 1 / Res;
    printf("Total resistance = %.5f", Res);

    return 0;
}
