/**
 * \file main.c
 * \brief Преобразовать исходную матрицу следующим образом:
 * удалить строку и столбец, на пересечении которых расположен элемент матрицы,
 * сумма цифр которого минимальна;
 *
 * Коды ошибок:
 *
 * -2 - в функцию delrowandcol переданы некорректные данные;
 *
 * -1 - в функцию racots или smallestinrow переданы некорректные данные;
 *
 * 1 - не все введённые значения были присвоены переменным;
 *
 * 2 - в функцию delrowandcol передано некорректное количество строк или
 * столбцов;
 *
 * 5 - в функцию printmas было передано некорректное значение строк или
 * столбцов;
 */

#include <stdio.h>

/**
 * \def NTWO
 * \brief Error code
 */
#define NTWO -2
/**
 * \def NONE
 * \brief Error code
 */
#define NONE -1
/**
 * \def ZERO
 * \brief OK code
 */
#define ZERO 0
/**
 * \def ONE
 * \brief Error code
 */
#define ONE 1
/**
 * \def TWO
 * \brief Error code
 */
#define TWO 2
/**
 * \def FIVE
 * \brief Error code
 */
#define FIVE 5
/**
 * \def TEN
 * \brief Делитель
 */
#define TEN 10

/**
 * \fn int getmat(int const row, int const col, int matrix[row][col])
 * \brief Функция получает элементы матрицы и размещает их в... Матрице!
 * Возвращает 2 при неверных параметрах, 1, если не все введённые значения были
 * присвоены переменным, 0, если всё прошло успешно
 *
 * \param [out] row Количество строк в матрице
 * \param [out] col Количество столбцов в матрице
 * \param [out] matrix[row][col] Указатель на матрицу
 * \return Код ошибки или успешного завершения
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

/**
 * \fn int printmat(int const row, int const col, int const printrow,
 * int const printcol, int mat[row][col])
 * \brief Функция вывода матрицы.
 *
 * \param [out] row Количество строк матрицы
 * \param [out] col Количество столбцов матрицы
 * \param [out] printrow Количество выводимых строк
 * \param [out] printcol Количество выводимых столбцов
 * \return 0 - удачное завершение, 5 - код ошибки
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

/**
 * \fn int sumofnum(int const num)
 * \brief Функция возвращает сумму цифр числа.
 *
 * \param [out] num Задаваемое число
 * \return Сумму цифр числа
 */
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

/**
 * \fn int racots(int const row, int const col, int mat[row][col])
 * \brief Функция нахождения в матрице строки с элементом, у которого сумма
 * цифр по всей матрице наименьшая
 *
 * \param [out] row Количество строк матрицы
 * \param [out] col Количество столбцов матрицы
 * \param [out] mat[row][col] Указатель на выводимую матрицу
 * \return Индекс строки, на которой находится элемент с наименьшей суммой цифр
 */
// "RowOfTheSmallest"
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

/**
 * \fn int smallestinrow(int const minr, int const row, int const col,
 * int mat[row][col])
 * \brief Функция нахождения в строке матрицы элемента, у которого сумма цифр
 * наименьшая.
 *
 * \param [out] minr Индекс строки, в которой изется требуемый элемент
 * \param [out] row Количество строк в матрице
 * \param [out] col Количество столбцов в матрице
 * \param [out] mat[row][col] Указатель на матрицу
 * \return 0 - удачное завершение, -1 - код ошибки
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

/**
 * \fn int delrowandcol(int const drow, int const dcol, int const row,
 * int const col, int mat[row][col])
 * \brief Функция удаляет указанные строку и столбец матрицы.
 *
 * \param [out] mas[] Указатель на выводимый массив
 * \param [out] num Количество элементов в массиве
 * \return 0 - удачное завершение, -2 - код ошибки
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