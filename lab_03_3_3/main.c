/*
 * Написать программу, которая обрабатывает двоичный
 * файл, содержащий целые числа.
 * Программа должна уметь:
 * − создавать файл и заполнять его случайными числами;
 * − выводить числа из файла на экран;
 * − упорядочивать числа в файле.
 */

/*
 * Выбран тип integer, алгоритм сортировки - quiсksort,
 * уморядочивание идёт по неуменьшению.
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int get_number_by_pos(FILE *in, const int pos, int *const number)
{
    if (!in)
        return -666666;
    if (pos < 0)
        return -666666;
    fseek(in, sizeof(int) * pos, SEEK_SET);
    fread(&(*number), sizeof(int), 1, in);
    return 0;
}

int put_number_by_pos(FILE *in, const int pos, const int number)
{
    if (!in)
        return -3;
    if (pos < 0)
        return -4;
    fseek(in, sizeof(int) * pos, SEEK_SET);
    fwrite(&number, sizeof(int), 1, in);
    return 0;
}

int binary_ints_to_mas(FILE *in, const int num, int mas[])
{
    if (!in)
        return -2;
    int pos = 0, rc;
    for (int i = 0; i < num; i++)
    {
        rc = get_number_by_pos(in, i, &mas[pos]);
        if (rc)
            return rc;
        pos++;
    }
    return 0;
}

int from_mas_to_bin_file(FILE *in, const int num, const int mas[])
{
    if (!in)
        return -2;
    if (num < 0)
        return 1;
    int rc;
    for (int i = 0; i < num; i++)
    {
        rc = put_number_by_pos(in, i, mas[i]);
        if (rc)
            return rc;
    }
    return 0;
}

void quicksort(int mas[], int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = mas[(left + right) / 2];
        while (left <= right)
        {
            while (mas[left] < middle)
                left++;
            while (mas[right] > middle)
                right--;
            if (left <= right)
            {
                int tmp = mas[left];
                mas[left] = mas[right];
                mas[right] = tmp;
                left++;
                right--;
            }
        }
        quicksort(mas, first, right);
        quicksort(mas, left, last);
    }
}

int find_size_of_bin(FILE *in)
{
    if (!in)
        return -2;
    fseek(in, 0, SEEK_SET);
    int size = 0, num, n = fread(&num, sizeof(int), 1, in);
    while (n)
    {
        size++;
        n = fread(&num, sizeof(int), 1, in);
    }
    return size;
}

int print_bin(FILE *in)
{
    if (!in)
        return -2;
    fseek(in, 0, SEEK_SET);
    int i = 0, num, n = fread(&num, sizeof(int), 1, in);
    while (n)
    {
        printf("%d ", num);
        n = fread(&num, sizeof(int), 1, in);
        i++;
    }
    return 0;
}

int main(const int argc, const char *const argv[])
{
    setbuf(stdout, NULL);
    if (argc != 3)
        return -666;
    if (*argv[1] == 's')
    {
        FILE *in = fopen(argv[2], "rb");
        if (!in)
            return -2;
        int number = find_size_of_bin(in);
        if (number == 0)
            return -3;
        if (number < 0)
            return number;
        int mas[number];
        int rc = binary_ints_to_mas(in, number, mas);
        if (rc < 0)
            return rc;
        fclose(in);
        quicksort(mas, 0, number);
        in = fopen(argv[2], "wb");
        from_mas_to_bin_file(in, number, mas);
        fclose(in);
    }
    else if (*argv[1] == 'p')
    {
        FILE *in = fopen(argv[2], "rb");
        if (!in)
            return -2;
        int rc = print_bin(in);
        if (rc < 0)
            return rc;
        if (rc == 0)
            return -333;
    }
    else if (*argv[1] == 'm')
    {
        FILE *in = fopen(argv[2], "wb");
        if (!in)
            return -2;
        int number;
        srand(time(NULL));
        for (int i = 0; i < 0; i++)
        {
            number = -100 + rand() % 200;
            put_number_by_pos(in, i, number);
        }
        fclose(in);
    }
    return 0;
}