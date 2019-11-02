#include <stdio.h>
#include <stdint.h>
#include "../headers/FM_neg_data.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define FREE_DATA_ERROR 11

int fm_neg_data(void)
{
    uint64_t **mat;

    int row = -1337;

    // Тест 1
    int die = 0, check = free_matrix(row, &mat);

    if (check)
        die++;

    // Тест 2
    row = 1;

    check = free_matrix(row, NULL);

    if (check)
        die++;

    if (check == 2)
        return SUCCESS;
    else
        return FREE_DATA_ERROR;
}
