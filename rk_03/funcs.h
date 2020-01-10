#ifndef __FUNCS_H__
#define __FUNCS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char **lex;
    int *bin;
}lexema;

int full_struct(lexema **mas, int len_mas, char **lexs, char **prev, int prev_len);

int lex_sort(int len, char ***mas);

int full_mas(FILE *f, char ***mas);


#endif
