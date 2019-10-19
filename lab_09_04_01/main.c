/**
 * \file main.с
 * \brief Лабораборная работа номер 9.
 * Вариант 4.
 * Задание: Принять с клавиатуры
 * 𝑚 ∈ N, 𝑛 ∈ N, 𝐴 ∈ 𝑀[𝑚×𝑛] (Z),
 * 𝑝 ∈ N, 𝑞 ∈ N, 𝐵 ∈ 𝑀[𝑝×𝑞] (Z).
 * Удаляя строки или столбцы, в соответствии с вариантом привести матрицы 𝐴 и 𝐵 к
 * квадратному виду 𝐴1 и 𝐵1:
 * 𝐴1 ∈ 𝑀[𝑘×𝑘](Z), where 𝑘 = min(𝑚, 𝑛),
 * 𝐵1 ∈ 𝑀[𝑠×𝑠](Z), where 𝑠 = min(𝑝, 𝑞).
 * Обратите внимание: если у матрицы больше строк, чем столбцов, то удалять нужно только
 * строки, иначе — только столбцы.
 * Добавляя в конец сначала строки, а потом столбцы, в соответствии с вариантом привести матрицы 𝐴1 и 𝐵1 к одному размеру 𝐴2 и 𝐵2:
 * 𝐴2, 𝐵2 ∈ 𝑀[𝑧×𝑧](Z), where 𝑧 = max(𝑘, 𝑠).
 * Приняв с клавиатуры целые неотрицательные 𝜌 и 𝛾, вычислить и вывести на экран результат выражения
 * 𝐴^𝜌|2𝐵^𝛾|2 = 𝐴2 · 𝐴2 · . . . · 𝐴2 · 𝐵2 · 𝐵2 · . . . · 𝐵2
 *                    𝜌 множителей           𝛾 множителей
 *
 * Для варианта 4:
 * Удалять строки или столбцы с максимальным элементом в матрице;
 * Если обнаружено несколько, считать целевым
 * максимум, который был бы встречен последним при обходе по стобцам;
 *
 * Добавлять в новые строки округлённые к нижнему целому средние арифметические элементов
 * столбцов;
 * Добавлять в новые столбцы минимумы по строкам;
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "headers/free_matrix.h"
#include "headers/make_fill_matrix.h"
#include "headers/print_mat.h"
#include "headers/del_to_sq.h"
#include "headers/add_rows.h"
#include "headers/add_cols.h"

#define SUCCESS 0
#define DATA_A_ERROR 1
#define DATA_B_ERROR 666
#define ULTRASATAN 666666
#define MEGAULTRASATAN 1337666
#define MEMORY_A_ERROR 9
#define MEMORY_B_ERROR 10
#define COMP_DATA_ERROR 14

#define DEBUG

/**
 * \fn int main()
 * \brief Точка входа в программу
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения (нуль)
 */
int main(void)
{
    FILE *in = stdin; // Поток ввода

    FILE *out = stdout; // Поток вывода

    if (!in || !out)
        return MEGAULTRASATAN;

    int check;

    int row_a, col_a;

    check = fscanf(in, "%d %d", &row_a, &col_a);

    if (check != 2)
        return DATA_A_ERROR;

    int64_t **matrix_a = (int64_t **)calloc(row_a, sizeof(int64_t **));

    if (!matrix_a)
        return DATA_A_ERROR;


    #ifdef DEBUG
    printf("/1/Я возьму телефон...");
    #endif
    check = make_fill_matrix(row_a, col_a, &matrix_a);

    if (check)
    {
        if (matrix_a)
            free_matrix(row_a, &matrix_a);
        return check;
    }

    int row_b, col_b;

    check = fscanf(stdin, "%d %d", &row_b, &col_b);

    if (check != 2)
        return DATA_B_ERROR;

    int64_t **matrix_b = (int64_t **)calloc(row_b, sizeof(int64_t **));

    if (!matrix_b)
        return DATA_A_ERROR;


    #ifdef DEBUG
    printf("/2/Наберу деканат...");
    #endif
    check = make_fill_matrix(row_b, col_b, &matrix_b);

    if (check)
    {
        if (matrix_b)
            free_matrix(row_b, &matrix_b);
        return check;
    }

    #ifdef DEBUG
    check = print_matrix(row_a, col_a, matrix_a, out);
    check = print_matrix(row_b, col_b, matrix_b, out);

    printf("/3/Деканат...");
    #endif
    while (row_a != col_a)
    {
        check = del_to_sq(&row_a, &col_a, &matrix_a);
        if (check != ULTRASATAN && check != SUCCESS)
            return MEMORY_A_ERROR;
    }


    #ifdef DEBUG
    printf("/4/Почему я хочу умереть?..");
    #endif
    while (row_b != col_b)
    {
        check = del_to_sq(&row_b, &col_b, &matrix_b);
        if (check != ULTRASATAN && check != SUCCESS)
            return MEMORY_B_ERROR;
    }

    if (row_a < row_b)
    {
        check = add_rows_till_sec(&row_a, col_a, row_b, &matrix_a);
        if (check)
            return check;

        check = add_cols_till_sec(&col_a, row_a, col_b, &matrix_a);
        if (check)
            return check;
    }
    else
    {
        check = add_rows_till_sec(&row_b, col_b, row_a, &matrix_b);
        if (check)
            return check;

        check = add_cols_till_sec(&col_b, row_b, col_a, &matrix_b);
        if (check)
            return check;
    }

/*
    #ifdef DEBUG
    printf("\n");
    print_matrix(row_a, col_a, matrix_a);
    printf("\n");
    print_matrix(row_b, col_b, matrix_b);
    #endif

*/

    int ro, gamma;
    check = fscanf(in, "%d %d", &ro, &gamma);

    if (check != 2)
        return COMP_DATA_ERROR;

    // Вызов функции перемножения матриц в форе от нуля до ро
    // Продолжение этой содомии
    // ДОБРО ПОЖАЛОВАТЬ В АД, АХАХХАХАХАХАХАХХАХАХАХХАХАХАХАХХ

    //Конец таска
    printf("\n");
    check = print_matrix(row_a, col_a, matrix_a, out);
    printf("\n");
    check = print_matrix(row_b, col_b, matrix_b, out);


    #ifdef DEBUG
    printf("Я возьму телефон...");
    #endif
    check = free_matrix(row_a, &matrix_a);

    #ifdef DEBUG
    printf("Наберу деканат...");
    #endif
    check = free_matrix(row_b, &matrix_b);
    return 0;
}
