#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/comp_mat.h"

#define SUCCESS 0
#define COMP_DATA_ERROR 44

int comp_mat(int row_a, int col_a, int row_b, int col_b, int64_t **mat_a, int64_t **mat_b, int64_t ***totmat)
{
    if (row_a < 1 || row_b < 1 || col_a < 1 || col_b < 1 || col_a != row_b || !mat_a || !mat_b || !totmat)
        return COMP_DATA_ERROR;

    for (int i = 0; i < col_b ; i++)
        for (int j = 0; j < row_a; j++)
        {
            *(*(*totmat + i) + j) = 0;
            for (int k = 0; k < col_a; k++)
                *(*(*totmat + i) + j) = *(*(*totmat + i) + j) + *(*(mat_a + i) + k) * *(*(mat_b + k) + j);
        }

    return SUCCESS;
}

