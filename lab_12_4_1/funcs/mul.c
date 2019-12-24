#include "../headers/main.h"

#define FILE_ERROR 020
#define READ_ERROR 021
#define NUM_ERROR 022

#define POINTER_ERROR -2

#define SUCCESS 0

int mul(void)
{
    if (!F_IN || !F_OUT)
        return FILE_ERROR;

    int num_f, num_s;

    int check = fscanf(F_IN, "%d %d", &num_f, &num_s);

    if (check != 2)
        return READ_ERROR;

    if (num_f <= 0 || num_s <= 0)
        return NUM_ERROR;

    node_t *first = out_list(num_f);

    node_t *second = out_list(num_s);


    if (num_f == 1 && num_s == 1)
    {
        fprintf(F_OUT, "1");
        return SUCCESS;
    }
    else if (num_f == 1)
        print_list(second);
    else if (num_s == 1)
        print_list(second);
    else
    {
        /// DEBAG
        ///print_list(first);
        ///printf("\n\n");
        ///print_list(second);
        ///printf("\n\n");
        ///
        node_t *total = mult_list(first, second);
        print_list(total);
        free_list(total);
    }


    if (first)
        free_list(first);
    if (second)
        free_list(second);

    return SUCCESS;
}
