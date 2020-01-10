#include "funcs.h"

int full_struct(lexema **mas, int len_mas, char **lexs, char **prev, int prev_len)
{
    int lex = 0;
    for (int i = 0; i < len_mas; i++)
    {
        if (!strcmp(lexs[i], "\n\0"))
            lex++;
    }

    *mas = calloc((unsigned)lex, sizeof(lexema));
    for (int i = 0; i < lex; i++)
    {
        (*mas + i)->lex = calloc(1, sizeof(char *));
        (*mas + i)->bin = calloc(prev_len, sizeof(int));
    }
    int cur = 0, cur_word = 0;
    for (int i = 0; i < len_mas; i++)
    {
        if (!strcmp(lexs[i], "\n\0"))
        {
            cur_word = 0;
            cur++;
        }
        else
        {
            *((*mas + cur)->lex + cur_word) = calloc(strlen(lexs[i] + 1), sizeof(char));
            strcpy(*((*mas + cur)->lex + cur_word), lexs[i]);
            cur_word++;
            (*mas + cur)->lex = realloc((*mas + cur)->lex, (cur_word + 1) * sizeof (char *));
            for (int j = 0; j < prev_len; j++)
            {
                if (!strcmp(*((*mas + cur)->lex + cur_word - 1), prev[j]))
                    *((*mas + cur)->bin + j - 1) = 1;
            }
        }
    }
    return lex;
}

