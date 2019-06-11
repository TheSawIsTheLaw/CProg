#include <stdio.h>

#define OHGOD 0
#define FILE_ERROR -1
#define MATRIX_FULLER_FAIL -3
#define DIMENSION_ERROR -4

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
    const long long int num, int matrix[num][num])
{
    if (!in)
        return FILE_ERROR;

    fseek(in, 0, SEEK_SET);

    int rc;
    char meme;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
           rc = fscanf(in, "%c", &meme);
           if (!rc)
               return MATRIX_FULLER_FAIL;

           if (meme != '\n')
               matrix[i][j] = meme;
           else
               j--;
        }
    }
    return OHGOD;
}

int mat_char_to_int(const long long int num, int matrix[num][num])
{
    if (num < 0)
        return DIMENSION_ERROR;
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
    return OHGOD;
}

int sqr_of_mat_in_file(FILE *const out,
    const long long int num,int matrix[num][num])
{
    if (!out)
        return FILE_ERROR;

    if (num < 0)
        return DIMENSION_ERROR;

    long long int sum = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            sum = 0;
            for (int q = 0; q < num; q++)
                sum = sum + matrix[i][q] * matrix[q][j];
            fprintf(out, "%d", (int)sum);
            /* Я знаю, что это неправильно, но блин, %I64lld и %I64d
             * не работают.
             */
        }
        fprintf(out, "\n");
    }

    return OHGOD;
}

int main(void)
{
    FILE *in = fopen("in.txt", "rt");

    if (!in)
        return FILE_ERROR;

    long long int num = find_rows_and_cols(in);

    int matrix[num][num], rc = full_mat_from_file(in, num, matrix);
    if (rc)
        return rc;

    fclose(in);

    rc = mat_char_to_int(num, matrix);
    if (rc)
        return rc;

    FILE *out = fopen("out.txt", "wt");
    if (!out)
        return FILE_ERROR;

    rc = sqr_of_mat_in_file(out, num, matrix);

    if(rc)
        return rc;

    fclose(out);
    return 0;
}
