/* Написать программу, которая обрабатывает двоичный
 * файл, содержащий целые числа.
 * Программа должна уметь:
 * − создавать файл и заполнять его случайными числами;
 * − выводить числа из файла на экран;
 * − упорядочивать числа в файле.
 */

/* Выбран тип integer, алгоритм сортировки - quiсksort,
 * уморядочивание идёт по неуменьшению.
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int get_number_by_pos(FILE *in, int row_pos, int col_pos, int row, int col)
{
    if (!in)
        return -666666;
    if (row_pos < 0 || col_pos < 0 || row < 0 || col < 0)
        return -666666;
    if (row_pos > row || col_pos > col)
        return -666666;
    fseek(in, sizeof(int) * (row_pos * col + col_pos), SEEK_SET);
    int number;
    fread(&number, sizeof(int), 1, in);
    return number;
}

int put_number_by_pos(FILE *in, int row_pos, int col_pos, int row, int col, int number)
{
    if (!in)
        return -3;
    if (row_pos < 0 || col_pos < 0 || row < 0 || col < 0)
        return -4;
    if (row_pos > row || col_pos > col)
        return -5;
    fseek(in, sizeof(int) * (row_pos * col + col_pos), SEEK_SET);
    fwrite(&number, sizeof(int), 1, in);
    printf("Pos row %d, col %d is number %d\n", row_pos, col_pos, number);
    return 0;
}

int binary_ints_to_mas(FILE *in, int row, int col, int mas[])
{
    if (!in)
        return -2;
    int pos = 0;
    printf("In mas we have: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mas[pos] = get_number_by_pos(in, i, j, row, col);
            printf("%d ", mas[pos]);
            if (mas[pos] == -666666)
                return -6;
            pos++;
        }
    }
    return 0;
}

int from_mas_to_bin_file(FILE *in, int row, int col, int mas[])
{
    if (!in)
        return -2;
    if (row < 0 || col < 0)
        return 1;
    int m;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Position is %d;\n", row * i * col + j);
            m = put_number_by_pos(in, i, j, row, col, mas[i * col + j]);
            if (m)
                return m;
        }
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

int main(void)
{
    char name[20];
    int m = scanf("%s", name);
    if (!m)
        return -1;
    FILE *in = fopen(name, "wb");
    if (!in)
        return -2;
    int row = ROWS, col = COLS, number;
    srand(time(NULL));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            number = -100 + rand() % 200;
            put_number_by_pos(in, i, j, row, col, number);
        }
    }
    fclose(in);
    
    in = fopen(name, "rb");
    if (!in)
        return -2;
    int mas[row * col] = { 0 };
    m = binary_ints_to_mas(in, row, col, mas);
    if (m < 0)
        return m;
    fclose(in);
    quicksort(mas, 0, row * col - 1);
    in = fopen(name, "wb");
    printf("Sorted mas: ");
    for (int i = 0; i < row * col; i++)
        printf("%d ", mas[i]);
    printf("And for sorted:\n");
    from_mas_to_bin_file(in, row, col, mas);
    fclose(in);
    return 0;
}