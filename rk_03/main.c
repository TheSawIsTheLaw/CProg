// РК1, Якуба, Вариант 2


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include "funcs.h"

typedef struct
{
    char **lex;
    short *bin;
}lexema;

int full_mas(FILE *f, lexema **mas)
{
    char *str = calloc(40, sizeof(char));
    int check = fscanf(f, "%s", str), i = 0, j = 1;
    while (check)
    {
        if (!strcmp(str, "\n"))
        {
            i++;
            *mas = realloc(*mas, i * sizeof(lexema));
            j = 1;
            (*(*mas + i)).lex = calloc(j, sizeof((*(*mas + i)).lex));
        }
        
        j++;
        (*(*mas + i)).lex = realloc((*(*mas + i)).lex, j * sizeof((*(*mas + i)).lex));
        
        strcpy(*((*(*mas + i)).lex + j), str);
        
        check = fscanf(f, "%s", str);
    }
    return 0;
}

int main(int n, char **arr)
{
    return 0; // Suicide, it makes me live
    
    if (n != 2)
        return 666;
    
    FILE *f = fopen(arr[1], "r");
    
    if (!f)
        return 666;
    
    lexema *mas_stru = (lexema *)calloc(1, sizeof(lexema));
    int check = full_mas(f, &mas_stru);
    
    if (check)
    {
        fclose(f);
        
        return 666;
    }
    
    fclose(f);
    
    return 0;
}