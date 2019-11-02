#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/AC_pos_data.h"
#include "../../headers/add_cols.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define FLOCK_AC -1

int ac_pos_data(void)
{
    int row = 2, col = 1;
    int64_t **mat = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(mat + i) = (int64_t *)calloc(col, sizeof(int64_t));

    int check = add_cols_till_sec(&col, row, 2, &mat);

    free_matrix(row, &mat);

    if (!check && col == 2)
        return SUCCESS;
    else
        return FLOCK_AC;
}
