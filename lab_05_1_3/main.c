/**
 * \file main.c
 * \brief Упорядочить строки матрицы по убыванию их наибольших элементов;
 *
 * Коды ошибок:
 *
 * 1 - не все введённые значения были присвоены переменным;
 *
 * 2 - введено некорректное количество строк и столбцов;
 *
 * 5 - в функцию printmat было передано некорректное значение строк или
 * столбцов;
 *
 * 6 - в функцию sortmaxrows было передано некорректное количество строк или
 * столбцов;
 *
 * 666666 - в функцию findmaxinrow были переданы некорректные значения
 * количества строк или столбцов;
 */

#include <stdio.h>

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
 * \def SIX
 * \brief Error code
 */
#define SIX 6
/**
 * \def DOUBLESATAN
 * \brief Error code
 */
#define DOUBLESATAN 666666

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
 * \fn int printmat(int const row, int const col, int mat[row][col])
 * \brief Функция вывода матрицы.
 *
 * \param [out] row Количество строк матрицы
 * \param [out] col Количество столбцов матрицы
 * \return 0 - удачное завершение, 5 - код ошибки
 */
int printmat(int const row, int const col, int mat[row][col])
{
    if (row < ZERO || col < ZERO)
        return FIVE;
    for (int i = ZERO; i < row; i++)
    {
        for (int j = ZERO; j < col; j++)
            printf("%d ", mat[i][j]);
    }
    return ZERO;
}

/**
 * \fn int findmaxinrow(int const row, int const col, int const numrow,
 * int mat[row][col])
 * \brief Функция ищет максимальное значение в заданной строке матрицы.
 *
 * \param [out] row Количество строк матрицы
 * \param [out] col Количество столбцов матрицы
 * \param [out] numrow Строка, в которой ищется элемент
 * \param [out] mat[row][col] Указатель на матрицу
 * \return Значение максимального элемента или код ошибки
 */
int findmaxinrow(int const row, int const col, int const numrow,
    int mat[row][col])
{
    if (row < TWO || col < TWO || numrow > row - ONE)
        return DOUBLESATAN;
    int max = mat[numrow][ZERO];
    for (int i = ONE; i < col; i++)
    {
        if (mat[numrow][i] > max)
        {
            max = mat[numrow][i];
        }
    }
    return max;
}

/**
 * \fn int sortmaxrows(int const row, int const col, int mat[row][col])
 * \brief Функция сортирует строки матрицы по убыванию их наибольших элементов.
 *
 * \param [out] row Количество строк матрицы
 * \param [out] col Количество столбцов матрицы
 * \param [out] mat[row][col] Указатель на матрицу
 * \return Код ошибки или успешного завершения
 */
int sortmaxrows(int const row, int const col, int mat[row][col])
{
    if (row < TWO || col < TWO)
        return SIX;
    int maxnow, maxfund, mem;
    for (int k = ZERO; k < row; k++)
    {
        for (int i = ZERO; i < row - ONE; i++)
        {
            maxnow = findmaxinrow(row, col, i, mat);
            if (maxnow == DOUBLESATAN)
                return maxnow;
            maxfund = findmaxinrow(row, col, i + ONE, mat);
            if (maxfund == DOUBLESATAN)
                return maxfund;
            if (maxnow < maxfund)
            {
                for (int j = ZERO; j < col; j++)
                {
                    mem = mat[i][j];
                    mat[i][j] = mat[i + ONE][j];
                    mat[i + ONE][j] = mem;
                }
            }
        }
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
        rc = sortmaxrows(row, col, matrix);
        if (rc)
            return rc;
        rc = printmat(row, col, matrix);
        if (rc)
            return rc;
    }
    return 0;
}
