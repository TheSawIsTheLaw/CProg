#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/add_cols.h"

#define SUCCESS 0
#define DATA_ADD_COLS_ERROR 11

int add_cols_till_sec(int *col_a, int row_a, int col_b, int64_t ***mat)
{
    if (!col_a || *col_a < 1 || row_a < 1 || col_b < 1 || !mat || *col_a > col_b)
        return DATA_ADD_COLS_ERROR;

    if (*col_a == col_b)
        return SUCCESS;

    int64_t min;

    for (int i = 0; i < row_a; i++)
    {
        min = **(*mat + i);
        for (int j = 0; j < *col_a; j++)
            if (min > *(*(*mat + i) + j))
                min = *(*(*mat + i) + j);
        *(*mat + i) = (int64_t *)realloc(*(*mat + i), col_b * sizeof(int64_t *));
        for (int k = *col_a; k < col_b; k++)
            *(*(*mat + i) + k) = min;
    }

    *col_a = col_b;

    return SUCCESS;
}
