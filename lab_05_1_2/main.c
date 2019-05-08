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
#define THREE 3
#define FOUR 4
#define FIVE 5

/* Коды ошибок:
 * -2 - в функцию удаления строки или столбца были переданы неверные данные
 * -1 - в функцию поиска столбца матрицы наименьшего по сумме цифр числа
 * или в функцию поиска того же числа в строке матрицы переданы
 * неверные данные
 * 1 - не все введённые значения были присвоены переменным;
 * 2 - введено неверное количество строк и столбцов (< 2)
 * 5 - в функцию вывода массива было передано отрицательное значение строк или
 * (и) столбцов
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
int printmat(int const row, int const col, int const mat[row][col])
{
    if (row < ZERO || col < ZERO)
        return FIVE;
    for (int i = ZERO; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", mat[i][j]);
    }
    return ZERO;
}

// Функция возвращает сумму цифр числа.
int sumofnum (int const num)
{
    int numvar;
    if (num < 0)
        numvar = num * NONE;
    else
        numvar = num;
    int i = 1, sum = 0;
    while (numvar / i > 0)
    {
        sum += (numvar / i) % 10;
        i = i * 10;
    }
    return sum;
}

/* "RowOfTheSmallest"
 * Функция нахождения в матрице строки с элементом, у которого сумма цифр по
 * всей матрице наименьшая
 * Если в функцию переданы неверные значения количества строк или столбцов,
 * выдаёт минус единицу, иначе - 0
 */
int racots (int const row, int const col, int const mat[row][col])
{
    if (row < TWO || col < TWO)
        return NONE;
    int min = sumofnum(mat[ZERO][ZERO]), minr = 0, now;
    for (int i = 0; i < row - ONE; i++)
    {
        for (int j = 0; j < col - ONE; j++)
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
int smallestinrow (int const minr, int const row, int const col,
    int const mat[row][col])
{
    if (minr < 0 || col < TWO || row < TWO)
        return NONE;
    int min = sumofnum(mat[minr][ZERO]), minc = 0, now;
    for (int j = 0; j < col - ONE; j++)
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

int delrowandcol(int const drow, int const dcol, int const row, int const col,
    int mat[row][col])
{
    if (row < TWO || col < TWO || drow < ZERO || dcol < ZERO ||
        drow > row - ONE || dcol > col - ONE)
        return NTWO;
    for (int i = drow; i < row - ONE; i++)
    {
        for (int j = 0; j < col; j++)
            mat[i][j] = mat[i + ONE][j];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = dcol; j < col - ONE; j++)
            mat[i][j] = mat[i][j + ONE];
    }
    return ZERO;
}

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
            if (minrow < 0)
                return minrow;
            int mincol = smallestinrow(minrow, row, col, matrix);
            if (mincol < 0)
                return mincol;
            rc = delrowandcol(minrow, mincol, row, col, matrix);
            if (rc)
                return rc;
            row--;
            col--;
            rc = printmat(row, col, matrix);
            if (rc)
                return rc;
        }
        return 0;
}
