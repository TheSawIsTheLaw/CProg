#include "funcs.h"

int find_two_mas(lexema *mas, int len, int mas_len)
{
    int i_max = 0, j_max = 0, max = 0, new = 0;
    for (int i = 0; i < mas_len - 1; i++)
    {
        for (int j = i + 1; j < mas_len; j++)
        {
            for (int k = 0; k < len; k++)
            {
                new += *((mas + i)->bin + k) * (*((mas + j)->bin + k));
            }
            if (new > max)
            {
                i_max = i;
                j_max = j;
                max = new;
            }
        }
    }

    printf("\n\nНаиболее похожие предложения:\n");

    int i = 0;
    while (*((mas + i_max)->lex + i))
    {
        printf("%s ", *((mas + i_max)->lex + i));
        i++;
    }
    i = 0;
    printf("\n");
    while (*((mas + j_max)->lex + i))
    {
        printf("%s ", *((mas + j_max)->lex + i));
        i++;
    }

    return 0;
}
