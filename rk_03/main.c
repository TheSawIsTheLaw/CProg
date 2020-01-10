// РК1, Якуба, Вариант 1


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

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
