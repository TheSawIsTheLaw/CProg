#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/CM_neg_data.h"
#include "../../headers/copy_mat.h"
#include "../../headers/free_matrix.h"

#define SUCCESS 0
#define COPY_DATA_ERROR 359

//#define DEBUG

int cm_neg_data(void)
{
    int64_t **mat_to = calloc(1, sizeof(int64_t)), **mat_f = calloc(1, sizeof(int64_t));

    int row, col;

    #ifdef DEBUG
    printf("Тут лик :)");
    #endif

    // Тест 1
    row = -13;
    col = 1;

    int die = 0, check = copy_mat(mat_f, row, col, &mat_to);

    if (check == COPY_DATA_ERROR)
        die++;

    // Тест 2
    row = 1;
    col = -1337;

    #ifdef DEBUG
    printf("Тут лик :)");
    #endif

    check = copy_mat(mat_f, row, col, &mat_to);

    if (check == COPY_DATA_ERROR)
        die++;

    // Тест 3
    check = copy_mat(NULL, row, col, &mat_to);

    if (check == COPY_DATA_ERROR)
        die++;

    // Тест 4
    check = copy_mat(mat_f, row, col, NULL);

    if (check == COPY_DATA_ERROR)
        die++;

    free_matrix(1, &mat_f);
    free_matrix(1, &mat_to);

    if (die == 4)
        return SUCCESS;
    else
        return COPY_DATA_ERROR;
}
