/* По матрице получить одномерный массив, присвоив его k-тому элементу значение
 * 1, если выполняется указанное ниже условие, и значение 0 иначе:
 * k-ая строка матрицы симметрична;
 */

#include <stdio.h>

#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5

/* Коды ошибок:
 * 1 - не все введённые значения были присвоены переменным;
 * 2 - введены неверные значения row или col (< 1)
 * 3 - введено неверное значение k (или row, или col в функцию переданы
 * неверно, в данной программе этот момент не может быть задействован. Обидно.)
 * 4 - передан неверный элемент замены в функцию replace (только 1 или 0)
 * 5 - в функцию printmas как-то попало неверное значение количества элементов
 * массива
 */

/* Функция получает элементы матрицы и размещает их в... Матрице!
 * Возвращает 2 при неверных параметрах, 1, если не все введённые значения были
 * присвоены переменным, 0, если всё прошло успешно.
 */
int getmat(int const row, int const col, int matrix[row][col])
{
    int rc = TWO;
    if (row <= ZERO || col <= ZERO)
        return rc;
    for (int i = ZERO; i < row; i++)
    {
        for (int j = ZERO; j < col; j++)
        {
            rc = scanf("%d", &matrix[i][j]);
            if (rc != ONE)
                return ONE;
        }
    }
    return ZERO;
}

/* Функция проверяет, расположены ли элементы k-ой строки матрицы симметрично.
 * 1 - да, 0 - нет, 3 - в функцию переданы неверные значения.
 */
int issim(int const row, int const col, int matrix[row][col],
    int const k)
{
    if (row < ONE || col < ONE || k < ZERO || k > row - ONE)
        return THREE;
    if (col == ONE)
        return col;
    int cown = col / TWO + ONE;
    for (int i = ZERO; i < cown; i++)
    {
        if (matrix[k][i] != matrix[k][col - ONE - i])
            return ZERO;
    }
    return ONE;
}

/* Функция сотворяет из матрицы массив, члены которого указывают на то,
 * является ли строка матрицы симметричной или нет. 1 - строка сим., 2 - иначе.
 * Возвращает значение 3, если получила на вход неправильные данные
 */
int makemasflagsim(int const row, int const col,
    int matrix[row][col], int mas[])
{
    int rc;
    if (row < ONE || col < ONE)
        return THREE;
    int i = ZERO;
    while (i < row)
    {
        rc = issim(row, col, matrix, i);
        if (rc == THREE)
            return THREE;
        if (rc)
            mas[i] = ONE;
        else
            mas[i] = ZERO;
        i++;
    }
    return ZERO;
}

/* Функция вывода массива, если передано неверное кол-во членов массива
 * возвращает 5, иначе возвращает 0
 */
int printmas(int const mas[], const int number)
{
    if (number < ZERO)
        return FIVE;
    for (int i = ZERO; i < number; i++)
        printf("%d ", mas[i]);
    return ZERO;
}

// Точка входа в программу
int main(void)
{
    int row, col, rc;
    rc = scanf("%d%d", &row, &col);
    if (rc != TWO)
        return ONE;
    else
    {
        if (row < ONE || col < ONE)
            return TWO;
        int matrix[row][col];
        rc = getmat(row, col, matrix);
        if (rc)
            return rc;
        int mas[row];
        rc = makemasflagsim(row, col, matrix, mas);
        if (rc)
            return rc;
        rc = printmas(mas, row);
        if (rc)
            return rc;
    }
    return 0;
}