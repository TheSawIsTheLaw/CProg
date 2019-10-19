#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/free_matrix.h"

#define SUCCESS 0
#define FREE_DATA_ERROR 2

int free_matrix(int row, uint64_t ***mat)
{
    if (row <= 0)
        return FREE_DATA_ERROR;

    for (int i = 0; i < row; i++)
    {
        if (*(*mat + i))
            free(*(*mat + i));
    }

    free(*mat);

    return SUCCESS;
}
