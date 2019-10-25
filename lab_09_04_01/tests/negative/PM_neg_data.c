#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../headers/PM_neg_data.h"
#include "../../headers/print_mat.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define PRINT_DATA_ERROR 6

int pm_neg_data(void)
{
    int64_t **mat = calloc(1, sizeof(int64_t));

    int row = 1, col = -666666;

    // Тест 1

    int die = 0, check = print_matrix(row, col, mat, stdout);

    if (check)
        die++;

    // Тест 2
    row = -666666;
    col = 1;

    check = print_matrix(row, col, mat, stdout);

    if (check)
        die++;

    // Тест 3
    row = 1;

    check = print_matrix(row, col, NULL, stdout);

    if (check)
        die++;

    // Тест 4
    check = print_matrix(row, col, mat, NULL);

    if (check)
        die++;

    free_matrix(1, &mat);

    if (die == 4)
        return SUCCESS;
    else
        return PRINT_DATA_ERROR;
}
