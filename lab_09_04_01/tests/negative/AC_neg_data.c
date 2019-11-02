#include <stdio.h>
#include <stdint.h>
#include "../headers/AC_neg_data.h"
#include "../../headers/add_cols.h"

#define SUCCESS 0
#define DATA_ADD_COLS_ERROR 11

int ac_neg_data(void)
{
    uint64_t **matrix;

    // Тест 1
    int col_a = -666, col_b = 1, row_a = 1;

    int die = 0;

    int check = add_cols_till_sec(&col_a, row_a, col_b, &matrix);

    if (check == DATA_ADD_COLS_ERROR)
        die++;

    // Тест 2
    col_a = 1;
    row_a = -777;

    check = add_cols_till_sec(&col_a, row_a, col_b, &matrix);

    if (check == DATA_ADD_COLS_ERROR)
        die++;

    // Тест 3
    row_a = 1;
    col_b = -359;

    check = add_cols_till_sec(&col_a, row_a, col_b, &matrix);

    if (check == DATA_ADD_COLS_ERROR)
        die++;

    // Тест 4
    col_b = 1;
    col_a = 2;

    check = add_cols_till_sec(&col_a, row_a, col_b, &matrix);

    if (check == DATA_ADD_COLS_ERROR)
        die++;

    col_a = 1;

    // Тест 5
    check = add_cols_till_sec(NULL, row_a, col_b, &matrix);

    if (check == DATA_ADD_COLS_ERROR)
        die++;

    // Тест 6

    check = add_cols_till_sec(&col_a, row_a, col_b, NULL);

    if (check == DATA_ADD_COLS_ERROR)
        die++;

    if (die == 6)
        return SUCCESS;
    else
        return DATA_ADD_COLS_ERROR;
}
