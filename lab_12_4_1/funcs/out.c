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

    int *prime_array = (int *)calloc((unsigned int)(num - 1), sizeof(int));

    int new_size = make_prime_array(prime_array, num);
    if (new_size <= 0)
        return NUM_ERROR;

    int *help = (int *)realloc(prime_array, (unsigned int)new_size * sizeof(int));
    if (help)
    {
        prime_array = help;
        help = 0;
    }
    else
    {
        free(prime_array);
        return POINTER_ERROR;
    }

    node_t *list = NULL;

    for (int i = new_size - 1; i >= 0; i--)
    {
        if (!(num % prime_array[i]))
        {
            node_t *node = calloc(1, sizeof(node_t));
            node->degree = 1;
            node->prime = prime_array[i];
            num = num / prime_array[i];
            while (!(num % prime_array[i]))
            {
                node->degree += 1;
                num = num / prime_array[i];
            }
            node->next = (struct node_t *)list;
            list = node;
        }
        if (num == 1)
            break;
    }

    print_list(list);

    free_list(list);

    free(prime_array);

    return SUCCESS;
}

