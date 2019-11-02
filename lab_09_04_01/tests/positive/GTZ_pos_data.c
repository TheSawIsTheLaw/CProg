#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/GTZ_pos_data.h"
#include "../../headers/go_to_zero.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define FLOCK_GTZ -8

int gtz_pos_data(void)
{
    int row = 2, col = 2;
    int64_t **mat = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(mat + i) = (int64_t *)calloc(col, sizeof(int64_t));

    int check = mat_to_zero(&mat, row, col);

    int back_back_back_to_zero = 1;

    for (int i = 0; i < row; i++)
        if (!(*(*(mat + i) + i)))
        {
            back_back_back_to_zero = 0;
            break;
        }

    free_matrix(row, &mat);

    if (!check || back_back_back_to_zero)
        return SUCCESS;
    else
        return FLOCK_GTZ;
}



