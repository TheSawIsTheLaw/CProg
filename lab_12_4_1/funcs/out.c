#include "../headers/main.h"

#define FILE_ERROR 010
#define READ_ERROR 011
#define NUM_ERROR 012

#define POINTER_ERROR -1

#define SUCCESS 0

int out(void)
{
    if (!F_IN || !F_OUT)
        return FILE_ERROR;

    int num;
    int check = fscanf(F_IN, "%d", &num);

    if (check != 1)
        return READ_ERROR;

    if (num <= 0)
        return NUM_ERROR;

    if (num == 1)
    {
        fprintf(F_OUT, "1");
        return SUCCESS;
    }

    node_t *list = out_list(num);

    print_list(list);

    free_list(list);

    return SUCCESS;
}

