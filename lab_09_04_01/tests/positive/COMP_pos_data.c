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
    int64_t **matI = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(matI + i) = (int64_t *)calloc(col, sizeof(int64_t));

    **matI = 1;

    int64_t **matII = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(matII + i) = (int64_t *)calloc(col, sizeof(int64_t));

    **matII = 1;

    int64_t **tot = (int64_t **)calloc(row, sizeof(int64_t));

    for (int i = 0; i < row; i++)
        *(tot + i) = (int64_t *)calloc(col, sizeof(int64_t));

    int check = comp_mat(row, col, row, col, matI, matII, &tot);

    if (!(**tot))
        check = FLOCK_COMP;

    free_matrix(row, &matI);
    free_matrix(row, &matII);
    free_matrix(row, &tot);

    if (!check)
        return SUCCESS;
    else
        return FLOCK_COMP;
}




