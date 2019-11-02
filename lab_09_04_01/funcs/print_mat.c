#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "../headers/print_mat.h"

#define SUCCESS 0
#define PRINT_DATA_ERROR 6

int print_matrix(int row, int col, int64_t **mat, FILE *out)
{
    if (row <= 0 || col <= 0 || !mat || !*mat || !out)
        return PRINT_DATA_ERROR;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            fprintf(out, "%" PRId64 " ", *(*(mat + i) + j));
        fprintf(out, "\n");
    }

    return SUCCESS;
}
