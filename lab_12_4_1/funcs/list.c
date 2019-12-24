#include "../headers/main.h"

#define POINTER_ERROR -1

void free_list(node_t *node)
{
    if (!node)
        return ;
    node_t *cur_node = node;
    while(cur_node->next)
    {
        node = (node_t *)node->next;
        free(cur_node);
        cur_node = node;
    }
    free(node);
}

void print_list(node_t *node)
{
    if (!node || !F_OUT)
        return ;

    node_t *node_x = node;
    while(node_x)
    {
        fprintf(F_OUT, "%d %d ", node_x->prime, node_x->degree);
        node_x = (node_t *)node_x->next;
    }
    fprintf(F_OUT, "1");
}

int make_prime_array(int *array, int num)
{
    if (!array)
        return POINTER_ERROR;

    for (int i = 2; i <= num; i++)
    {
        array[i - 2] = i;
    }

    int cur_num = num - 1;
    for (int i = 0; i < cur_num; i++)
    {
        for (int j = i + 1; j < cur_num; j++)
        {
            if (!(array[j] % array[i]))
            {
                for (int k = j + 1; k < cur_num; k++)
                    array[k - 1] = array[k];
                cur_num--;
                j--;
            }
        }
    }

    return cur_num;
}

node_t *out_list(int num)
{
    if (!F_IN)
        return NULL;

    if (num <= 0)
        return NULL;

    if (num == 1)
        return NULL;

    int *prime_array = (int *)calloc((unsigned int)(num - 1), sizeof(int));

    int new_size = make_prime_array(prime_array, num);
    if (new_size <= 0)
        return NULL;

    int *help = (int *)realloc(prime_array, (unsigned int)new_size * sizeof(int));
    if (help)
    {
        prime_array = help;
        help = 0;
    }
    else
    {
        free(prime_array);
        return NULL;
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

    free(prime_array);

    return list;
}

node_t *mult_list(node_t *first, node_t *second)
{
    if (!first || !second)
        return NULL;

    node_t *new = calloc(1, sizeof(node_t)), *start_l = new, *pre = NULL;

    while (first && second)
    {
        if (first->prime == second->prime)
        {
            new->prime = first->prime;
            new->degree = first->degree + second->degree;
            first = (node_t *)first->next;
            second = (node_t *)second->next;
        }
        else if (first->prime > second->prime)
        {
            new->prime = second->prime;
            new->degree = second->degree;
            second = (node_t *)second->next;
        }
        else
        {
            new->prime = first->prime;
            new->degree = first->degree;
            first = (node_t *)first->next;
        }
        new->next = calloc(1, sizeof(node_t));
        pre = new;
        new = (node_t *)new->next;
    }

    while (first)
    {
        new->prime = first->prime;
        new->degree = first->degree;
        first = (node_t *)first->next;
        new->next = calloc(1, sizeof(node_t));
        pre = new;
        new = (node_t *)new->next;
    }

    while (second)
    {
        new->prime = second->prime;
        new->degree = second->degree;
        second = (node_t *)second->next;
        new->next = calloc(1, sizeof(node_t *));
        pre = new;
        new = (node_t *)new->next;
    }

    if (pre)
        free(pre->next);
    pre->next = NULL;

    return start_l;

    /* Вы только гляньте, меня б в дурку с такими идеями...
    while (first->next)
    {
        new->prime = first->prime;
        new->degree = first->degree;
        new->next = calloc(1, sizeof(node_t));
        new = (node_t *)new->next;
        first = (node_t *)first->next;
    }
    new->next = NULL;
    new->prime = first->prime;
    new->degree = first->degree;

    node_t *sec_cur = second;

    new = list;
    while (sec_cur)
    {
        while (new)
        {
            if (new->prime < sec_cur->prime)
            {
                new = (node_t *)new->next;
            }
            else if (new->prime == sec_cur->prime)
            {
                new->degree += sec_cur->degree;
            }
            else
            {
                node_t *n_n = calloc(1, sizeof(node_t *));
                n_n->prime = sec_cur->prime;
                n_n->degree = sec_cur->degree;
                n_n->next = new->next;
                new->next = (struct node_t *)n_n;
            }
        }

        sec_cur = (node_t *)sec_cur->next;
    }*/

}

