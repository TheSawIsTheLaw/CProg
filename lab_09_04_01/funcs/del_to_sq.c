#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/del_to_sq.h"

#define SUCCESS 0
#define DATA_DEL_ERROR 7
#define MEMORY_ERROR 8
#define ULTRASATAN 666666

int del_to_sq(int *row, int *col, int64_t ***mat)
{
    if (!row || !col || *row < 1 || *col < 1 || !mat || !*mat)
        return DATA_DEL_ERROR;

    if (*row == *col)
        return ULTRASATAN;

    int64_t max = ***mat;

    int64_t max_col = 0, max_row = 0;

    for (int j = 0; j < *col; j++)
    {
        for (int i = 0; i < *row; i++)
        {
            if (*(*(*mat + i) + j) >= max)
            {
                max = *(*(*mat + i) + j);
                max_col = j;
                max_row = i;
            }
        }
    }

    if (*row > *col)
    {
        free(*(*mat + max_row));
        *row = *row - 1;
        for (int64_t i = max_row; i < *row; i++)
            *(*mat + i) = *(*mat + i + 1);
        *mat = (int64_t **)realloc(*mat, *row * sizeof(int64_t **));
        return SUCCESS;
    }
    else
    {
        *col = *col - 1;
        for (int i = 0; i < *row; i++)
        {
            for (int64_t j = max_col; j < *col; j++)
                *(*(*mat + i) + j) = *(*(*mat + i) + j + 1);
            *(*mat + i) = (int64_t *)realloc(*(*mat + i), *col * sizeof(int64_t *));
        }
        return SUCCESS;
    }
    return SUCCESS;
}
