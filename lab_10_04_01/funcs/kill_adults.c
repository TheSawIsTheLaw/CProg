#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/base.h"

#define CUR_YEAR 2019
#define CUR_MONTH 11
#define CUR_DAY 1

#define SUCCESS 0

#define KA_NILL_ERROR 200
#define KA_SATAN_LOOP 201

#define KI_PARAMS_ERROR 210
#define KI_MEMORY_ERROR 211

#define TO_KILL "ИУ7-31Б"

int kill_it(students **mas, const int i)
{
    if (i < 0 || !mas)
        return KI_PARAMS_ERROR;
    int j = i;
    free((*mas + j)->group);
    free((*mas + j)->marks);
    free((*mas + j)->surname);
    free((*mas + j)->birthday);
    while (strcmp((*mas + j + 1)->group, "none"))
    {
        (*mas + j)->group = (*mas + j + 1)->group;
        (*mas + j)->birthday = (*mas + j + 1)->birthday;
        (*mas + j)->q_marks = (*mas + j + 1)->q_marks;
        (*mas + j)->surname = (*mas + j + 1)->surname;
        (*mas + j)->marks = (*mas + j + 1)->marks;
        j++;
    }
    (*mas + j)->group = (*mas + j + 1)->group;
    (*mas + j)->surname = NULL;
    (*mas + j)->marks = NULL;
    (*mas + j)->surname = NULL;
    (*mas + j)->birthday = NULL;
    (*mas + j + 1)->group = NULL;

    students *new = realloc(*mas, (j + 1) * sizeof(students));
    if (!new)
        return KI_MEMORY_ERROR;
    *mas = new;
    new = NULL;

    return SUCCESS;
}

int kill_adults(students **mas, int *ser_quan)
{
    if (!mas || !*mas || !ser_quan)
        return KA_NILL_ERROR;

    int i = 0, check = 0;

    while(strcmp((*mas + i)->group, "none"))
    {
        DEB("IN DA KILL")
        if (!strcmp((*mas + i)->group, TO_KILL))
        {
            /// !
            /// ! ВНИМАНИЕ! СЛЕДУЮЩИЕ ТРИ "ИФА" НЕ ДЛЯ СЛАБОНЕРВНЫХ!
            /// ! ПРОДОЛЖАЙТЕ ПРОСМОТР НА СВОЙ СТРАХ И РИСК!
            /// !
            /// ! ALARMA!!! GO AWAY! YOU DON'T WANT TO SEE THIS RASPUTITSA!
            /// ! (занятный факт: слово "распутица" действительно присутствует в английском языке)
            /// ! (но написал я его, конечно же, неправильно)
            /// !

            if (CUR_YEAR - *((*mas + i)->birthday) > 17)
            {
                check = kill_it(mas, i);
                if (check)
                    return check;
                i--;
            }
            else if (CUR_YEAR - *((*mas + i)->birthday) == 17 && CUR_MONTH - *((*mas + i)->birthday + 1) > 0)
            {
                check = kill_it(mas, i);
                if (check)
                    return check;
                i--;
            }
            /// ! Данный вариант развития событий не особо хотелось добавлять, но всё во имя универсальности!
            else if (CUR_YEAR - *((*mas + i)->birthday) == 17 &&
                CUR_MONTH - *((*mas + i)->birthday + 1) == 0 &&
                CUR_DAY - *((*mas + i)->birthday + 2) < 0)
            {
                check = kill_it(mas, i);
                if (check)
                    return check;
                i--;
            }
            if (check)
                return check;
        }
        i++;

        if (i == 66666)
            return KA_SATAN_LOOP;
    }
    *ser_quan = i;

    return SUCCESS;
}
