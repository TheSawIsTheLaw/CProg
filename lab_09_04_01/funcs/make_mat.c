#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "../headers/make_fill_matrix.h"

#define SUCCESS 0
#define MAKE_DATA_ERROR 3
#define MAKE_CALL_ERROR 4
#define SCAN_MAT_ERROR 5

int make_fill_matrix(int row, int col, int64_t ***mat)
{
    if (row <= 0 || col <= 0 || !mat)
        return MAKE_DATA_ERROR;

    for (int i = 0; i < row; i++)
    {
        *(*mat + i) = (int64_t *)calloc(col, sizeof(int64_t *));

        if (!*(*mat + i))
            return MAKE_CALL_ERROR;

        short check;

        for (int j = 0; j < col; j++)
        {
            check = scanf("%" SCNd64, (*(*mat + i) + j));
            if (!check)
                return SCAN_MAT_ERROR;
        }
    }

    return SUCCESS;
}
