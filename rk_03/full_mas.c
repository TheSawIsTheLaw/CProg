#include "funcs.h"

int full_mas(FILE *f, char ***mas)
{
    char word[40];
    int i = 1;
    char *new;
    char symb;
    while (fscanf(f, "%s", word) != -1)
    {
        new = calloc(strlen(word), sizeof(char));
        strcpy(new, word);

        *mas = realloc(*mas, (i + 1) * sizeof(char *));
        *(*mas + i - 1) = new;
        i++;
        fscanf(f, "%c", &symb);
        if (symb == '\n')
        {
            *(*mas + i - 1) = "\n\0";
            i++;
        }
    }

    return i;
}
