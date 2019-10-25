#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../headers/DTS_neg_data.h"
#include "../../headers/del_to_sq.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define DATA_DEL_ERROR 7

int dts_neg_data(void)
{
    int64_t **mat = calloc(1, sizeof(int64_t));

    int row, col;

    // Тест 1
    row = -666;
    col = 1;

    int die = 0, check = del_to_sq(&row, &col, &mat);

    if (check)
        die++;

    // Тест 2
    row = 1;
    col = -666;

    check = del_to_sq(&row, &col, &mat);

    if (check)
        die++;

    col = 1;

    // Тест 3
    check = del_to_sq(NULL, &col, &mat);

    if (check)
        die++;

    // Тест 4
    check = del_to_sq(&row, NULL, &mat);

    if (check)
        die++;

    // Тест 5
    check = del_to_sq(&row, &col, &mat);

    if (check)
        die++;

    free_matrix(1, &mat);

    if (die == 5)
        return SUCCESS;
    else
        return DATA_DEL_ERROR;
}

