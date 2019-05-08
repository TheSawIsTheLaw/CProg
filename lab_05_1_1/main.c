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
 * 2 - введены неверные значения row или col (< 2)
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
int issim(int const row, int const col, int const matrix[row][col],
    int const k)
{
    if (row < TWO || col < TWO || k - ONE < ZERO || k - ONE > col)
        return THREE;
    for (int i = ZERO; i < (row - ONE) / TWO; i++)
    {
        if (matrix[k - ONE][i] != matrix[k - ONE][row - i - ONE])
            return ZERO;
    }
    return ONE;
}

/* Функция сотворяет из матрицы массив.
 * 0 - всё свершилось без ошибок, 3 - в функцию переданы неверные значения.
 */
int makemasfrommat(int const row, int const col,
    int const matrix[row - ONE][col - ONE], int mas[])
    {
    if (row < ONE || col < ONE)
        return THREE;
    int num = row * col;
    int i = ZERO, j = ZERO, k = ZERO;
    while (i < num)
    {
        while (j < col)
        {
            mas[i] = matrix[k][j];
            j++;
            i++;
        }
        j = ONE;
        k++;
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

/* Функция заменяет k-ый элемент массива на значение insk.
 * 0 - всё завершилось без происшествий, 3 - в функцию были переданы неверные
 * значения количества членов массива или индекс заменяемого элемента, 4 -
 * значение, которым мы пытаемся заменить k-ый элемент не является 1 или 0
 */
int replace(int const num, int mas[], int const insk, int const k)
{
    if (num < ONE || k - ONE < ZERO || k > num)
        return THREE;
    if (insk != ONE && insk != ZERO)
        return FOUR;
    mas[k - ONE] = insk;
    return ZERO;
}

// Точка входа в программу
int main(void)
{
    int row, col, k, rc;
    rc = scanf("%d%d%d", &row, &col, &k);
    if (rc != THREE)
        return ONE;
    else
    {
        if (row <= TWO || col <= TWO)
            return TWO;
        if (k < ONE || k > row)
            return THREE;
        int matrix[row][col];
        rc = getmat(row, col, matrix);
        if (rc)
            return rc;
        int insk = issim(row, col, matrix, k);
        if (insk == THREE)
            return insk;
        int mas[row*col];
        rc = makemasfrommat(row, col, matrix, mas);
        if (rc)
            return rc;
        int num = row*col;
        rc = replace(num, mas, insk, k);
        if (rc)
            return rc;
        rc = printmas(mas, num);
        if (rc)
            return rc;
    }

    return 0;
}