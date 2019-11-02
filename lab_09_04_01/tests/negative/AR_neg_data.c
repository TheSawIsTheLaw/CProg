#include <stdio.h>
#include <stdint.h>
#include "../headers/AR_neg_data.h"
#include "../../headers/add_rows.h"

#define SUCCESS 0
#define DATA_ADD_ROWS_ERROR 11

int ar_neg_data(void)
{
    uint64_t **matrix;

    // Тест 1
    int row_a = -666, col_a = 1, row_b = 1;

    int die = 0;

    int check = add_rows_till_sec(&row_a, col_a, row_b, &matrix);

    if (check == DATA_ADD_ROWS_ERROR)
        die++;

    // Тест 2
    row_a = 1;
    col_a = -777;

    check = add_rows_till_sec(&row_a, col_a, row_b, &matrix);

    if (check == DATA_ADD_ROWS_ERROR)
        die++;

    // Тест 3
    col_a = 1;
    row_b = -359;

    check = add_rows_till_sec(&row_a, col_a, row_b, &matrix);

    if (check == DATA_ADD_ROWS_ERROR)
        die++;

    // Тест 4
    row_b = 1;
    row_a = 2;

    check = add_rows_till_sec(&row_a, col_a, row_b, &matrix);

    if (check == DATA_ADD_ROWS_ERROR)
        die++;

    row_a = 1;

    // Тест 5
    check = add_rows_till_sec(NULL, col_a, row_b, &matrix);

    if (check == DATA_ADD_ROWS_ERROR)
        die++;

    // Тест 6

    check = add_rows_till_sec(&row_a, col_a, row_b, NULL);

    if (check == DATA_ADD_ROWS_ERROR)
        die++;

    if (die == 6)
        return SUCCESS;
    else
        return DATA_ADD_ROWS_ERROR;
}

