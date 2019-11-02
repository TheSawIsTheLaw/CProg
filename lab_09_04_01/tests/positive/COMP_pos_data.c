#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/COMP_pos_data.h"
#include "../../headers/comp_mat.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define FLOCK_COMP -10

int comp_pos_data(void)
{
    int row = 2, col = 2;
    int64_t **mati = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(mati + i) = (int64_t *)calloc(col, sizeof(int64_t));

    **mati = 1;

    int64_t **matii = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(matii + i) = (int64_t *)calloc(col, sizeof(int64_t));

    **matii = 1;

    int64_t **tot = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(tot + i) = (int64_t *)calloc(col, sizeof(int64_t));

    int check = comp_mat(row, col, row, col, mati, matii, &tot);

    if (!(**tot))
        check = FLOCK_COMP;

    free_matrix(row, &mati);
    free_matrix(row, &matii);
    free_matrix(row, &tot);

    if (!check)
        return SUCCESS;
    else
        return FLOCK_COMP;
}
