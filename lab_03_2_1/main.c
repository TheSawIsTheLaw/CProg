/*
 * Пользователь вводит целые числа, по окончании ввода чисел вводит букву (в Windows для
 * ввода в окне cmd признака EOF можно нажать Ctrl-Z и Enter).
 * находит порядковый номер максимального из чисел (если чисел с максимальным
 * значением несколько, то должен быть найден номер первого из них);
 */

#include <stdio.h>

int find_max_in_row(FILE *in, int *const index)
{
    if (!in)
        return -2;
    int q, i = 1, ind = 1, n = fscanf(in, "%d", &q);
    if (n != 1)
        return -3;
    int max = q;
    while (n == 1)
    {
        if (q > max)
        {
            ind = i;
            max = q;
        }
        n = fscanf(in, "%d", &q);
        i++;
    }
    *index = ind;
    return 0;
}

int main(void)
{
    FILE *in = stdin;
    if (!in)
        return -1;
    int index = 0, n = find_max_in_row(in, &index);
    if (n)
        return n;
    else
        printf("%d", index);
    return 0;
}