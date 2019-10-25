#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/AR_pos_data.h"
#include "../../headers/add_rows.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define FLOCK_AR -2

int ar_pos_data(void)
{
    int row = 1, col = 2;
    int64_t **mat = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(mat + i) = (int64_t *)calloc(col, sizeof(int64_t));

    int check = add_rows_till_sec(&row, col, 2, &mat);

    free_matrix(row, &mat);

    if (!check && row == 2)
        return SUCCESS;
    else
        return FLOCK_AR;
}
