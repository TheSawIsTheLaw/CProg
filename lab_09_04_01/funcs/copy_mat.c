#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "../headers/copy_mat.h"

#define SUCCESS 0
#define COPY_DATA_ERROR 1488

int copy_mat(int64_t **mat_f, int row, int col, int64_t ***mat_to)
{
    if (!mat_f || !mat_to || row < 1 || col < 1)
        return COPY_DATA_ERROR;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            *(*(*mat_to + i) + j) = *(*(mat_f + i) + j);
    }

    return SUCCESS;
}

