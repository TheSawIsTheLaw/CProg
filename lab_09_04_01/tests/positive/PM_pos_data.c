#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/PM_pos_data.h"
#include "../../headers/print_mat.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define FLOCK_PM -9

int pm_pos_data(void)
{
    int row = 2, col = 2;
    int64_t **mat = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(mat + i) = (int64_t *)calloc(col, sizeof(int64_t));

    int check = print_matrix(row, col, mat, stdout);

    free_matrix(row, &mat);

    if (!check)
        return SUCCESS;
    else
        return FLOCK_PM;
}




