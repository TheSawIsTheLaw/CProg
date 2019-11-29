#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/base.h"

#define NULL_ERROR -666666
#define FS_EMPTY_ERROR -100

#define SUCCESS 0


int free_students(students **mas, int quan)
{
    if (!mas)
        return NULL_ERROR;

    int i = 0;

    while (i < quan)
    {
        if ((*mas + i)->group)
            free((*mas + i)->group);

        if ((*mas + i)->surname)
            free((*mas + i)->surname);

        if ((*mas + i)->birthday)
            free((*mas + i)->birthday);

        if ((*mas + i)->marks)
            free((*mas + i)->marks);
        i++;
    }
    if ((*mas + i)->group)
        free((*mas + i)->group);

    free(*mas);

    if (!quan)
        return FS_EMPTY_ERROR;

    return SUCCESS;
}
