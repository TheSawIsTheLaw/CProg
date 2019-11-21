#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/base.h"

#define CUR_YEAR 2019
#define CUR_MONTH 11
#define CUR_DAY 1

#define SUCCESS 0

#define KA_NILL_ERROR 200
#define KI_PARAMS_ERROR 210
#define KI_MEMORY_ERROR 211
#define KI_EMPTY 212

int kill_it(students *mas, const int i)
{
    if (i < 0 || !mas)
        return KI_PARAMS_ERROR;
    int j = i;
    free((mas + i)->group);
    free((mas + i)->marks);
    free((mas + i)->surname);
    free((mas + i)->birthday);
    free(mas + i);
    while (strcmp((mas + j + 1)->group, "none"))
    {
        *(mas + j) = *(mas + j + 1);
        j++;
    }
    *(mas + j) = *(mas + j + 1);
    free((mas + j + 1)->group);
    free(mas + j + 1);
    if (j == 0)
        return KI_EMPTY;
    students *new = realloc(mas, j * sizeof(students));
    if (!new)
        return KI_MEMORY_ERROR;
    mas = new;
    new = NULL;

    return SUCCESS;
}

int kill_adults(students *mas)
{
    if (!mas)
        return KA_NILL_ERROR;

    int i = 0, check = 0;

    while(strcmp((mas + i)->group, "none"))
    {
        if (!strcmp((mas + i)->group, "ИУ7-31Б"))
        {
            /// !
            /// ! ВНИМАНИЕ! СЛЕДУЮЩИЕ ТРИ "ИФА" НЕ ДЛЯ СЛАБОНЕРВНЫХ!
            /// ! ПРОДОЛЖАЙТЕ ПРОСМОТР НА СВОЙ СТРАХ И РИСК!
            /// !
            /// ! ALARMA!!! GO AWAY! YOU DON'T WANT TO SEE THIS RASPUTITSA!
            /// ! (занятный факт: слово "распутица" действительно присутствует в английском языке)
            /// ! (но написал я его, конечно же, неправильно)
            /// !
             if (CUR_YEAR - *((mas + i)->birthday + 2) > 17)
                 check = kill_it(mas, i);
             else if (CUR_YEAR - *((mas + i)->birthday + 2) == 17 && CUR_MONTH - *((mas + i)->birthday + 1) > 0)
                 check = kill_it(mas, i);
             /// ! Данный вариант развития событий не особо хотелось добавлять, но всё во имя универсальности!
             else if (CUR_YEAR - *((mas + i)->birthday + 2) == 17 &&
                 CUR_MONTH - *((mas + i)->birthday + 1) == 0 &&
                 CUR_DAY - *((mas + i)->birthday) < 0)
                 check = kill_it(mas, i);
             if (check)
                 return check;
        }
        i++;
    }

    return SUCCESS;
}
