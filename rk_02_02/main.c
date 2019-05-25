#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *in = fopen("in.txt", "rt");
    FILE *out = fopen("out.txt", "wt");
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
            if (sym == ' ')
            {
                fprintf(out, " ");
            }
            else
            {
                fprintf(out, "%d", k);
                k = 0;
            }
            n = fscanf(in, "%c", &sym);
        }
    }
    fclose(in);
    fclose(out);
}
