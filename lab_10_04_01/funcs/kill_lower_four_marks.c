#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/base.h"

#define SUCCESS 0

#define KLFM_NILL_ERROR 300
#define KLFM_MEMORY_ERROR 301
#define KLFM_SATAN_LOOP 302

int kill_lower_four_marks(students **mas)
{
    if (!mas || !*mas)
            return KLFM_NILL_ERROR;

    int flag = 0, i = 0;

    float *new;

    while(strcmp((*mas + i)->group, "none"))
    {
        for (int j = 0; j < (*mas + i)->q_marks; j++)
        {
            if (*((*mas + i)->marks + j) < 4)
            {
                (*mas + i)->q_marks = (*mas + i)->q_marks - 1;
                for (int k = j; k < (*mas + i)->q_marks; k++)
                    *((*mas + i)->marks + k) = *((*mas + i)->marks + k + 1);
                flag = 1;
                j--;
            }
        }
        if (flag)
        {
            flag = 0;

            DEB("HA-HA, REAL")

            new = realloc((*mas + i)->marks, (*mas + i)->q_marks * sizeof(float));
            if (new)
            {
                (*mas + i)->marks = new;
                new = NULL;
            }
            else
                return KLFM_MEMORY_ERROR;
        }
        i++;

        if (i == 66666)
            return KLFM_SATAN_LOOP;
    }

    return SUCCESS;
}


