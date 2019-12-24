#include "../headers/main.h"

#define FILE_ERROR 040
#define READ_ERROR 041
#define NUM_ERROR 042

#define POINTER_ERROR -4

#define SUCCESS 0

int sqr(void)
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

    node_t *new = out_list(num);

    node_t *cur = new;

    while (cur->next)
    {
        cur->degree *= 2;
        cur = (node_t *)cur->next;
    }
    cur->degree *= 2;

    print_list(new);

    new = NULL;

    free_list(new);

    return SUCCESS;
}
