#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/CM_pos_data.h"
#include "../../headers/copy_mat.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define FLOCK_CM -3

int cm_pos_data(void)
{
    int row = 2, col = 2;
    int64_t **mat_f = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(mat_f + i) = (int64_t *)calloc(col, sizeof(int64_t));

    *((*(mat_f + 1)) + 1) = 666;

    int64_t **mat_to = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(mat_to + i) = (int64_t *)calloc(col, sizeof(int64_t));

    int check = copy_mat(mat_f, row, col, &mat_to);

    if (*((*(mat_to + 1)) + 1) == 666)
        col = 666;

    free_matrix(row, &mat_f);
    free_matrix(row, &mat_to);

    if (!check && col == 666)
        return SUCCESS;
    else
        return FLOCK_CM;
}

