// РК1, Якуба, Вариант 1


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include "funcs.h"

typedef struct
{
    char **lex;
    int *bin;
}lexema;

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

int main(int n, char **arr)
{
    if (n != 2)
        return 666;
    FILE *f = fopen(arr[1], "r");


    if (!f)
        return 666;

    char **mas = calloc(1, sizeof(char *));
    int check = full_mas(f, &mas);

    fclose(f);
    if (check < 0)
        return check;
    int mas_len = check - 1, mas_2_len = mas_len;

    lexema *lex_mas;

    char **mas_2 = calloc(mas_len, sizeof(char *));
    for (int i = 0; i < mas_len; i++)
    {
        printf("%s ", *(mas + i));
        *(mas_2 + i) = calloc(strlen(*(mas + i)), sizeof(char));
        strcpy(*(mas_2 + i), *(mas + i));
    }

    mas_len = del_ununiq(mas_len, &mas);

    lex_sort(mas_len, &mas);
    for (int i = 0; i < mas_len; i++)
    {
        printf("%s ", *(mas + i));
    }
    check = full_struct(&lex_mas, mas_2_len, mas_2, mas, mas_len);


    FILE *out = fopen("out.txt", "w");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < mas_len - 1; j++)
        {
            fprintf(out, "%d ", *((lex_mas + i)->bin + j));
        }
        fprintf(out, "\n");
    }
    fclose(out);

    find_two_mas(lex_mas, mas_len, check);

    return 0;
}
