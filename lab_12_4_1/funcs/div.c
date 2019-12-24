#include "../headers/main.h"

#define FILE_ERROR 030
#define READ_ERROR 031
#define NUM_ERROR 032

#define POINTER_ERROR -3

#define SUCCESS 0

int my_div(void)
{
    if (!F_IN || !F_OUT)
        return FILE_ERROR;

    int num_f, num_s;

    int check = fscanf(F_IN, "%d %d", &num_f, &num_s);

    if (check != 2)
        return READ_ERROR;

    if (num_f <= 0 || num_s <= 0)
        return NUM_ERROR;

    div_t num = div(num_f, num_s);

    if (!num.quot)
        return NUM_ERROR;

    if (num.quot == 1)
    {
        fprintf(F_OUT, "1");
        return SUCCESS;
    }

    node_t *new = out_list(num.quot);

    print_list(new);

    free_list(new);

    return SUCCESS;
}
