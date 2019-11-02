#include <stdio.h>
#include <stdint.h>
#include "../headers/go_to_zero.h"

#define SUCCESS 0
#define BACK_TO_ZERO_DATA_ERROR 911

int mat_to_zero(int64_t ***mat, int row, int col)
{
    if (!mat || row < 1 || col < 1)
        return BACK_TO_ZERO_DATA_ERROR;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
                *(*(*mat + i) + j) = 1;
            else
                *(*(*mat + i) + j) = 0;
        }
    }

    return SUCCESS;
}
