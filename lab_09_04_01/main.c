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
#include "headers/comp_mat.h"
#include "headers/copy_mat.h"
#include "headers/go_to_zero.h"

#define SUCCESS 0
#define DATA_A_ERROR 1
#define DATA_B_ERROR 666
#define ULTRASATAN 666666
#define MEGAULTRASATAN 1337666
#define MEMORY_A_ERROR 9
#define MEMORY_B_ERROR 10
#define COMP_DATA_ERROR 14

//#define DEBUG

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

    if (check != 2 || row_a < 1 || col_a < 1)
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

    if (check != 2 || row_b < 1 || row_a < 1)
    {
        free_matrix(row_a, &matrix_a);

        return DATA_B_ERROR;
    }

    int64_t **matrix_b = (int64_t **)calloc(row_b, sizeof(int64_t **));

    if (!matrix_b)
    {
        free_matrix(row_a, &matrix_a);

        return DATA_B_ERROR;
    }


    #ifdef DEBUG
    printf("/2/Наберу деканат...");
    #endif
    check = make_fill_matrix(row_b, col_b, &matrix_b);

    if (check)
    {
        if (matrix_b)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);
        }
        else
            free_matrix(row_a, &matrix_a);
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
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);
            return MEMORY_A_ERROR;
        }
    }


    #ifdef DEBUG
    printf("/4/Почему я хочу умереть?..");
    #endif
    while (row_b != col_b)
    {
        check = del_to_sq(&row_b, &col_b, &matrix_b);
        if (check != ULTRASATAN && check != SUCCESS)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);
            return MEMORY_B_ERROR;
        }
    }

    if (row_a < row_b)
    {
        check = add_rows_till_sec(&row_a, col_a, row_b, &matrix_a);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);
            return check;
        }

        check = add_cols_till_sec(&col_a, row_a, col_b, &matrix_a);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);
            return check;
        }
    }
    else
    {
        check = add_rows_till_sec(&row_b, col_b, row_a, &matrix_b);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);
            return check;
        }

        check = add_cols_till_sec(&col_b, row_b, col_a, &matrix_b);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            return check;
        }
    }

    int ro, gamma;
    check = fscanf(in, "%d %d", &ro, &gamma);

    if (check != 2 || ro < 0 || gamma < 0)
    {
        free_matrix(row_a, &matrix_a);

        free_matrix(row_b, &matrix_b);

        return COMP_DATA_ERROR;
    }

    int64_t **total = (int64_t **)calloc(row_a, sizeof(int64_t **));
    int64_t **total_copy = (int64_t **)calloc(row_a, sizeof(int64_t **));
    int64_t **total_fir = (int64_t **)calloc(row_a, sizeof(int64_t **));
    int64_t **total_sec = (int64_t **)calloc(row_a, sizeof(int64_t **));

    if (!total || !total_copy || !total_fir || !total_sec)
    {
        free_matrix(row_a, &matrix_a);

        free_matrix(row_b, &matrix_b);

        if (total)
            free_matrix(row_a, &total);
        if (total_copy)
            free_matrix(row_a, &total_copy);
        if (total_fir)
            free_matrix(row_a, total_fir);
        if (total_sec)
            free_matrix(row_a, total_sec);

        return ULTRASATAN;
    }

    for (int i = 0; i < col_b; i++)
    {
        *(total_sec + i) = (int64_t *)calloc(row_a, sizeof(int64_t *));
        *(total_fir + i) = (int64_t *)calloc(row_a, sizeof(int64_t *));
        *(total_copy + i) = (int64_t *)calloc(row_a, sizeof(int64_t *));
        *(total + i) = (int64_t *)calloc(row_a, sizeof(int64_t *));

        if (!*(total_sec + i) || !*(total_fir + i) || !*(total_copy + i) || !*(total + i))
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_a, &total);

            free_matrix(row_a, &total_copy);

            free_matrix(row_a, total_fir);

            free_matrix(row_a, total_sec);

            return ULTRASATAN;
        }
    }

    if (!ro)
    {
        check = mat_to_zero(&matrix_a, row_a, col_a);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
        check = copy_mat(matrix_a, row_a, col_a, &total_fir);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
    }
    else if (ro == 1)
    {
        check = copy_mat(matrix_a, row_a, col_a, &total_fir);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
    }
    else
    {
        check = comp_mat(row_a, col_a, row_b, col_b, matrix_a, matrix_a, &total);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
    }

    #ifdef DEBUG
    printf("\n");
    check = print_matrix(row_b, col_b, total, out);
    printf("\n");
    check = print_matrix(row_b, col_b, total_copy, out);
    #endif

    for (int i = 2; i < ro; i++)
    {
        check = copy_mat(total, row_a, col_a, &total_copy);
        #ifdef DEBUG
        printf("\n");
        check = print_matrix(row_b, col_b, total_copy, out);
        #endif
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
        check = comp_mat(row_a, col_a, row_b, col_b, total_copy, matrix_a, &total);
        #ifdef DEBUG
        printf("\n");
        check = print_matrix(row_b, col_b, total, out);
        #endif
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
    }

    if (ro != 1 && ro != 0)
    {
        check = copy_mat(total, row_a, col_a, &total_fir);
        //check = print_matrix(row_b, col_b, total, out);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
    }


    if (!gamma)
    {
        check = mat_to_zero(&matrix_b, row_b, col_b);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
        check = copy_mat(matrix_b, row_b, col_b, &total_sec);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
    }
    else if (gamma == 1)
    {
        check = copy_mat(matrix_b, row_a, col_a, &total_sec);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
    }
    else
    {
        check = comp_mat(row_a, col_a, row_b, col_b, matrix_b, matrix_b, &total);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
    }

    for (int i = 2; i < gamma; i++)
    {
        check = copy_mat(total, row_a, col_a, &total_copy);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
        check = comp_mat(row_a, col_a, row_b, col_b, total_copy, matrix_b, &total);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
    }
    if (gamma != 1 && gamma != 0)
    {
        check = copy_mat(total, row_a, col_a, &total_sec);
        //check = print_matrix(row_b, col_b, total, out);
        if (check)
        {
            free_matrix(row_a, &matrix_a);

            free_matrix(row_b, &matrix_b);

            free_matrix(row_b, &total);

            free_matrix(row_b, &total_copy);

            free_matrix(row_b, &total_sec);

            free_matrix(row_b, &total_fir);

            return check;
        }
    }

    check = comp_mat(row_a, col_a, row_b, col_b, total_fir, total_sec, &total);
    if (check)
    {
        free_matrix(row_a, &matrix_a);

        free_matrix(row_b, &matrix_b);

        free_matrix(row_b, &total);

        free_matrix(row_b, &total_copy);

        free_matrix(row_b, &total_sec);

        free_matrix(row_b, &total_fir);

        return check;
    }

    //Конец таска
    printf("\n");
    check = print_matrix(row_b, col_b, total, out);

    #ifdef DEBUG
    printf("Я возьму телефон...");
    #endif
    free_matrix(row_a, &matrix_a);

    free_matrix(row_b, &matrix_b);

    free_matrix(row_b, &total);

    free_matrix(row_b, &total_copy);

    free_matrix(row_b, &total_sec);

    free_matrix(row_b, &total_fir);

    return 0;
}
