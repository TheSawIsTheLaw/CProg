/**
 * \file main.c
 * \brief По матрице получить одномерный массив, присвоив его k-тому элементу
 * значение 1, если выполняется указанное ниже условие, и значение 0 иначе:
 * k-ая строка матрицы симметрична;
 *
 * Коды ошибок:
 *
 * 1 - не все введённые значения были присвоены переменным;
 *
 * 2 - введены некорректные значения количества строк или столбцов;
 *
 * 3 - в функцию issim было передано некорректные параметры;
 *
 * 4 - в функцию makemasflagsim было передано некорректное количество строк
 * или столбцов;
 *
 * 5 - в функцию printmas передано некорректное количество членов массива;
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
 * \def THREE
 * \brief Error code
 */
#define THREE 3
/**
 * \def FOUR
 * \brief Error code
 */
#define FOUR 4
/**
 * \def FIVE
 * \brief Error code
 */
#define FIVE 5

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
 * \fn int issim(int const row, int const col, int matrix[row][col],
 * int const k)
 * \brief Функция проверяет, расположены ли элементы k-ой строки матрицы
 *  симметрично
 *
 * \param [out] row Количество строк в матрице
 * \param [out] col Количество столбцов в матрице
 * \param [out] matrix[row][col] Указатель на матрицу
 * \param [out] k Номер строки
 * \return Код ошибки или успешного завершения
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

/**
 * \fn int makemasflagsim(int const row, int const col,
 * int matrix[row][col], int mas[])
 * \brief Функция сотворяет из матрицы массив, члены которого указывают на то,
 * является ли строка матрицы симметричной или нет.
 *
 * \param [out] row Количество строк в матрице
 * \param [out] col Количество столбцов в матрице
 * \param [out] matrix[row][col] Указатель на матрицу
 * \param [out] k Номер строки
 * \return 1 - строка симметрична, 0 - иначе. 3 - код ошибки
 */
int makemasflagsim(int const row, int const col,
    int matrix[row][col], int mas[])
{
    int rc;
    if (row < ONE || col < ONE)
        return FOUR;
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

/**
 * \fn int printmas(int const mas[], const int number)
 * \brief Функция вывода массива.
 *
 * \param [out] mas[] Указатель на выводимый массив
 * \param [out] num Количество элементов в массиве
 * \return 0 - удачное завершение, 5 - код ошибки
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
