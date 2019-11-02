#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/DTS_pos_sqr.h"
#include "../../headers/del_to_sq.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define FLOCK_DTS_S -6

int dts_pos_sqr(void)
{
    int row = 2, col = 2;
    int64_t **mat = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(mat + i) = (int64_t *)calloc(col, sizeof(int64_t));

    int check = del_to_sq(&row, &col, &mat);

    free_matrix(row, &mat);

    if (check == 666666)
        return SUCCESS;
    else
        return FLOCK_DTS_S;
}

