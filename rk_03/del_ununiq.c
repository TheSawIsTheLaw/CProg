#include "funcs.h"

int del_ununiq(int len, char ***mas)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (!strcmp(*(*mas + i), *(*mas + j)))
            {
                for (int k = j; k < len; k++)
                {
                    *(*mas + k) = *(*mas + k + 1);
                }
                j--;
                len--;
                *mas = realloc(*mas, len * sizeof(char *));
            }
        }
    }
    return len;
}
