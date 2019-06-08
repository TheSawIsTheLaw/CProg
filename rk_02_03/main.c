#include <stdio.h>
#include <string.h>

long long int find_rows_and_cols(FILE *const in)
{
    char sym;
    int n = fscanf(in, "%c", &sym);
    long long int num = 0;
    while (n != 0 && sym != '\n')
    {
        n = fscanf(in, "%c", &sym);
        num++;
    }
    return num;
}

int full_mat_from_file(FILE *const in,
    long long int num, int matrix[num][num])
{
    if (!in)
        return -1;

    fseek(in, 0, SEEK_SET);

    int rc;
    char meme;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
           rc = fscanf(in, "%c", &meme);
           if (!rc)
               return -3;

           if (meme != '\n')
               matrix[i][j] = meme;
           else
               j--;
        }
    }
    return 0;
}

int mat_char_to_int(const int num, int matrix[num][num])
{
    if (num < 0)
        return -4;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (matrix[i][j] == 48)
                matrix[i][j] = 0;
            else
                matrix[i][j] = 1;
        }
    }
    return 0;
}

int sqr_of_mat_in_file(FILE *const out,
    const long long int num,int matrix[num][num])
{
    long long int sum = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            sum = 0;
            for (int q = 0; q < num; q++)
            {
                printf("%d %d \n", matrix[i][q], matrix[q][j]);
                sum = sum + matrix[i][q] * matrix[q][j];
            }
            fprintf(out, "%I64d", sum);
        }
        fprintf(out, "\n");
    }

    return 0;
}

void print_mat(int num, int matrix[num][num])
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main(void)
{
    FILE *in = fopen("in.txt", "rt");

    if (!in)
        return -1;

    long long int num = find_rows_and_cols(in);

    int matrix[num][num], rc = full_mat_from_file(in, num, matrix);
    if (rc)
        return -2;

    fclose(in);

    rc = mat_char_to_int(num, matrix);
    if (rc)
        return -3;

    FILE *out = fopen("out.txt", "wt");
    if (!out)
        return -1;

    rc = sqr_of_mat_in_file(out, num, matrix);
    printf("\n\n");
    print_mat(num, matrix);

    if(rc)
        return -666;

    fclose(out);
    return 0;
}