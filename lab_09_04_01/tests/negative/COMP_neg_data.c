#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../headers/COMP_pos_data.h"
#include "../../headers/comp_mat.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define COMP_DATA_ERROR 44

int comp_neg_data(void)
{
    int64_t **mat = calloc(1, sizeof(int64_t));

    int row = 1, col = -666666;

    // Тест 1

    int die = 0, check = comp_mat(row, col, row, col, mat, mat, mat);

    if (check)
        die++;

    // Тест 2
    row = -666666;
    col = 1;

    check = comp_mat(row, col, row, col, mat, mat, mat);

    if (check)
        die++;

    // Тест 3
    row = 2;

    check = comp_mat(row, col, row, col, mat, mat, mat);

    if (check)
        die++;

    // Тест 4
    check = comp_mat(row, col, row, col, NULL, mat, mat);

    if (check)
        die++;

    // Тест 5
    check = comp_mat(row, col, row, col, mat, NULL, mat);

    if (check)
        die++;

    // Тест 6
    check = comp_mat(row, col, row, col, mat, mat, NULL);

    if (check)
        die++;

    free_matrix(1, &mat);

    if (die == 6)
        return SUCCESS;
    else
        return COMP_DATA_ERROR;
}
