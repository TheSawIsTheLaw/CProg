#include <stdio.h>
#include <stdint.h>
#include "../headers/GTZ_neg_data.h"
#include "../../headers/go_to_zero.h"

#define SUCCESS 0
#define BACK_TO_ZERO_DATA_ERROR 911

int gtz_neg_data(void)
{
    int64_t **mat;

    int row = 1, col = -666666;

    // Тест 1
    int die = 0, check = mat_to_zero(&mat, row, col);

    if (check)
        die++;

    // Тест 2
    row = -63636;
    col = 1;

    check = mat_to_zero(&mat, row, col);

    if (check)
        die++;

    // Тест 3
    row = 1;

    check = mat_to_zero(NULL, row, col);

    if (check)
        die++;

    if (die == 3)
        return SUCCESS;
    else
        return BACK_TO_ZERO_DATA_ERROR;
}
