#include "funcs.h"

int lex_sort(int len, char ***mas)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (strcmp(*(*mas + j), *(*mas + j + 1)) > 0)
            {
                char *word = *(*mas + j);
                *(*mas + j) = *(*mas + j + 1);
                *(*mas + j + 1) = word;
            }
        }
    }

    return 0;
}
