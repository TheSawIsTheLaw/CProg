#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/FM_pos_data.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define FLOCK_FM -7

int fm_pos_data(void)
{
    int row = 2, col = 2;
    int64_t **mat = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(mat + i) = (int64_t *)calloc(col, sizeof(int64_t));

    int check = free_matrix(row, &mat);

    if (!check)
        return SUCCESS;
    else
        return FLOCK_FM;
}


