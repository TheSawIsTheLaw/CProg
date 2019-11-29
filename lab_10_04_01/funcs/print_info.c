#include <stdio.h>
#include <string.h>

#include "../headers/base.h"

#define PI_FILE_ERROR 500

#define SUCCESS 0

int print_info(FILE *f, students *journal, int quan)
{
    if (!f)
        return PI_FILE_ERROR;

    int i = 0;

    while (i < quan - 1)
    {
        fprintf(f, "%s\n", (journal + i)->group);

        fprintf(f, "%s\n", (journal + i)->surname);

        fprintf(f, "%d.%d.%d\n", *((journal + i)->birthday), *((journal + i)->birthday + 1), *((journal + i)->birthday + 2));

        fprintf(f, "%d ", (journal + i)->q_marks);

        for (int j = 0; j < (journal + i)->q_marks; j++)
            fprintf(f, "%f ", *((journal + i)->marks + j));

        fprintf(f, "\n");

        i++;
    }

    return SUCCESS;
}


