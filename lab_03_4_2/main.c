/*
 * Написать программу, которая считывает из текстового файла вещественные числа и
 * выполняет над ними некоторые вычисления:
 * найти среднее значение чисел, расположенных между минимальным и максимальным
 * числами («между» - не по значению, а по расположению).
 */

#include <stdio.h>
#include <string.h>

int find_ind_max(FILE *in)
{
    if (!in)
        return -1;
    fseek(in, 0, SEEK_SET);
    float number;
    int n = fscanf(in, "%f", &number), i = 0, index = 0;
    if (!n)
        return -1;
    float max = number;
    while (n == 1)
    {
        if (number > max)
        {
            index = i;
            max = number;
        }
        n = fscanf(in, "%f", &number);
        i++;
    }
    return index;
}

int find_ind_min(FILE *in)
{
    if (!in)
        return -1;
    fseek(in, 0, SEEK_SET);
    float number;
    int n = fscanf(in, "%f", &number), i = 0, index = 0;
    if (!n)
        return -1;
    float min = number;
    while (n == 1)
    {
        if (number < min)
        {
            index = i;
            min = number;
        }
        n = fscanf(in, "%f", &number);
        i++;
    }
    return index;
}

float find_average_between_indices(FILE *in, int start, int end)
{
    if (!in)
        return -666666;
    if (start == end)
        return -666666;
    else if (start > end)
    {
        float memory = end;
        end = start;
        start = memory;
    }
   /*
    * fseek(in, sizeof(float) * (start + 1), SEEK_SET);
    * А потом я вспомнил, что это не бинарный файл.
    * А ведь с такими идеями мог бы и в Google попасть!..
    */
    fseek(in, 0, SEEK_SET);
    float number;
    int n = fscanf(in, "%f", &number);
    float average = 0;
    if (!n)
        return -1;
    int quantity = 0, i = 1;
    while (n == 1 && i < end + 1)
    {
        if (i > start + 1)
        {
            quantity++;
            average += number;
            printf("%d %f ", quantity, number);
        }
        n = fscanf(in, "%f", &number);
        i++;
    }
    average = average / quantity;
    return average;
}

int main(void)
{
    char name[20];
    int m = scanf("%s", name);
    if (!m)
        return -1;
    FILE *in = fopen(name, "rt");
    if (!in)
        return -2;
    int ind_max = find_ind_max(in);
    if (ind_max < 0)
        return -3;
    int ind_min = find_ind_min(in);
    if (ind_min < 0)
        return -3;
    if (ind_min == ind_max)
        return -4;
    float average = find_average_between_indices(in, ind_min, ind_max);
    if (average == -666666)
        return -5;
    printf("%f", average);
    fclose(in);
    return 0;
}