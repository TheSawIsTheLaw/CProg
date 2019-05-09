/* Преобразовать исходную матрицу следующим образом:
 * удалить строку и столбец, на пересечении которых расположен элемент матрицы,
 * сумма цифр которого минимальна;
 */

#include <stdio.h>

#define NTWO -2
#define NONE -1
#define ZERO 0
#define ONE 1
#define TWO 2
#define FIVE 5
#define TEN 10

/* Коды ошибок:
 * -2 - в функцию delrowandcol переданы некорректные данные;
 * -1 - в функцию racots или smallestinrow переданы некорректные данные;
 * 1 - не все введённые значения были присвоены переменным;
 * 2 - в функцию delrowandcol передано некорректное количество строк или
 * столбцов;
 * 5 - в функцию printmas было передано некорректное значение строк или
 * столбцов;
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

/* Функция вывода массива, если передано неверное кол-во членов массива
 * возвращает 5, иначе возвращает 0
 */
int printmat(int const row, int const col, int const printrow,
    int const printcol, int mat[row][col])
{
    if (row < ZERO || col < ZERO)
        return FIVE;
    for (int i = ZERO; i < printrow; i++)
    {
        for (int j = ZERO; j < printcol; j++)
            printf("%d ", mat[i][j]);
    }
    return ZERO;
}

// Функция возвращает сумму цифр числа
int sumofnum(int const num)
{
    int numvar;
    if (num < ZERO)
        numvar = num * NONE;
    else
        numvar = num;
    int i = ONE, sum = ZERO;
    while (numvar / i > ZERO)
    {
        sum += (numvar / i) % TEN;
        i = i * TEN;
    }
    return sum;
}

/* "RowOfTheSmallest"
 * Функция нахождения в матрице строки с элементом, у которого сумма цифр по
 * всей матрице наименьшая
 * Если в функцию переданы неверные значения количества строк или столбцов,
 * выдаёт -1, иначе - 0
 */
int racots(int const row, int const col, int mat[row][col])
{
    if (row < TWO || col < TWO)
        return NONE;
    int min = sumofnum(mat[ZERO][ZERO]);
    int minr = ZERO, now;
    for (int i = ZERO; i < row; i++)
    {
        for (int j = ZERO; j < col; j++)
        {
            now = sumofnum(mat[i][j]);
            if (now < min)
            {
                min = now;
                minr = i;
            }
        }
    }
    return minr;
}

/* Функция нахождения в строке матрицы элемента, у которого сумма цифр
 * наименьшая
 * Если в функцию переданы неверные значения количества строк или столбцов,
 * выдаёт минус единицу, иначе - 0
 */
int smallestinrow(int const minr, int const row, int const col,
    int mat[row][col])
{
    if (minr < ZERO || col < TWO || row < TWO)
        return NONE;
    int min = sumofnum(mat[minr][ZERO]), minc = ZERO, now;
    for (int j = ONE; j < col; j++)
    {
        now = sumofnum(mat[minr][j]);
        if (now < min)
        {
            min = now;
            minc = j;
        }
    }
    return minc;
}

/* Функция удаляет указанные строчку и столбец матрицы
 * Возвращает -2, если в функцию переданы некорректные параметры, 0, когда всё
 * прошло успешно
 */
int delrowandcol(int const drow, int const dcol, int const row, int const col,
    int mat[row][col])
{
    if (row < TWO || col < TWO || drow < ZERO || dcol < ZERO ||
        drow > row - ONE || dcol > col - ONE)
        return NTWO;
    for (int i = drow; i < row; i++)
    {
        for (int j = ZERO; j < col; j++)
            mat[i][j] = mat[i + ONE][j];
    }
    for (int i = ZERO; i < row; i++)
    {
        for (int j = dcol; j < col; j++)
            mat[i][j] = mat[i][j + ONE];
    }
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
        if (row < TWO || col < TWO)
            return TWO;
        int matrix[row][col];
        rc = getmat(row, col, matrix);
        if (rc)
            return rc;
        int minrow = racots(row, col, matrix);
        if (minrow < ZERO)
            return minrow;
        int mincol = smallestinrow(minrow, row, col, matrix);
        if (mincol < ZERO)
            return mincol;
        rc = delrowandcol(minrow, mincol, row, col, matrix);
        if (rc)
            return rc;
        rc = printmat(row, col, row - ONE, col - ONE, matrix);
        if (rc)
            return rc;
    }
    return 0;
}