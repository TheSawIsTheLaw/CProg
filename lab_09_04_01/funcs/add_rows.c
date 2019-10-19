#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/add_rows.h"

#define SUCCESS 0
#define DATA_ADD_ROWS_ERROR 11

int add_rows_till_sec(int *row_a, int col_a, int row_b, int64_t ***mat)
{
    if (!row_a || *row_a < 1 || row_b < 1 || !mat || *row_a > row_b || col_a < 1)
        return DATA_ADD_ROWS_ERROR;

    if (*row_a == row_b)
        return SUCCESS;

    *mat = (int64_t **)realloc(*mat, row_b * sizeof(int64_t **));

    int64_t sum = 0;

    while (*row_a < row_b)
    {
        *(*mat + *row_a) = (int64_t *)calloc(col_a, sizeof(int64_t *));
        for (int i = 0; i < col_a; i++)
        {
            for (int j = 0; j < *row_a; j++)
                sum = sum + *(*(*mat + j) + i);
            *(*(*mat + *row_a) + i) = (int64_t)(sum / (*row_a));
            sum = 0;
        }
        *row_a = *row_a + 1;
    }

    return SUCCESS;
}
