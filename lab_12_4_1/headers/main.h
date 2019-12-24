#ifndef ___MAIN_H___
#define ___MAIN_H___

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define F_OUT stdout
#define F_IN stdin

typedef struct
{
    int prime;
    int degree;
    struct node_t *next;
}node_t;

void free_list(node_t *node);

void print_list(node_t *node);

int make_prime_array(int *array, int num);

node_t *out_list(int num);

node_t *mult_list(node_t *first, node_t *second);

int out(void);

int mul(void);

int my_div(void);

int sqr(void);

#endif
