#include <stdio.h>
#include <string.h>

int inslen(FILE *in, FILE *out)
{
    if (!in)
    {
        return 1;
    }
    else
    {
        char sym;
        int n = fscanf(in, "%c", &sym), k = 0;
        while (n == 1)
        {
            if (sym == ' ' || sym == '\n' || sym == '\0')
            {
                if (k != 0)
                {
                    fprintf(out, "%d", k);
                    k = 0;
                }
                fprintf(out, "%c", sym);
            }
            else
            {
                k++;
            }
            n = fscanf(in, "%c", &sym);
        }
        fprintf(out, "%d", k);
    }
    return 0;
}

int main(void)
{
    FILE *in = fopen("in.txt", "rt");
    FILE *out = fopen("out.txt", "wt");
    int rc = inslen(in, out);
    if (rc)
        return rc;
    fclose(in);
    fclose(out);

}
