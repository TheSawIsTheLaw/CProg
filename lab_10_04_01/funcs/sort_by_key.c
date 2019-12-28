#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/base.h"

#define SUCCESS 0

#define SBK_KEY_ERROR 400
#define SBK_DATA_ERROR 401
#define MSG_MEMORY_ERROR 410

#define EQUAL 0
#define SMALLER -1
#define BIGGER 1

int comp_students_group(students *f_value, students *s_value)
{
    if (!f_value)
        return BIGGER;
    else if (!s_value)
        return SMALLER;

    return strcmp(f_value->group, s_value->group);
}

int comp_students_surname(students *f_value, students *s_value)
{
    if (!f_value || !(f_value->surname))
        return BIGGER;
    else if (!s_value || !(s_value->surname))
        return SMALLER;

    return strcmp(f_value->surname, s_value->surname);
}

int comp_students_marks(students *f_value, students *s_value)
{
    if (!f_value || !(f_value->marks))
        return BIGGER;
    else if (!s_value || !(s_value->marks))
        return SMALLER;

    float f_aver = 0, s_aver = 0;

    for (int i = 0; i < f_value->q_marks; i++)
        f_aver += *(f_value->marks + i);

    for (int i = 0; i < s_value->q_marks; i++)
        s_aver += *(s_value->marks + i);

    f_aver = f_aver / f_value->q_marks;
    s_aver = s_aver / s_value->q_marks;

    if (f_aver - s_aver < 0)
        return SMALLER;
    else if (f_aver - s_aver > 0)
        return BIGGER;
    else
        return EQUAL;
}

int merge_sort_students(students **mas, int quan, int (*comp)(students *, students *))
{
    students *buf = calloc(quan, sizeof(students));
    if (!buf)
        return MSG_MEMORY_ERROR;
    int mid = quan / 2;
    if (quan % 2)
        mid++;
    int h = 1;
    int step;
    int i = 0;   // Индекс первого пути
    int j; // Индекс второго пути
    int k;   // Индекс элемента в результирующей последовательности
    while (h < quan)
    {
        i = 0;
        k = 0;
        j = mid;
        step = h;
        while (step <= mid)
        {
            while ((i < step) && (j < quan) && (j < (mid + step)))
            {
                // Пока не дошли до конца пути
                // заполняем следующий элемент формируемой последовательности
                // меньшим из двух просматриваемых
                if (comp(*mas + i, *mas + j) <= 0)
                {
                    DEB((*mas + i)->group)
                    (buf + k)->group = (*mas + i)->group;
                    (buf + k)->surname = (*mas + i)->surname;
                    (buf + k)->marks = (*mas + i)->marks;
                    (buf + k)->q_marks = (*mas + i)->q_marks;
                    (buf + k)->birthday = (*mas + i)->birthday;
                    i++;
                    k++;
                }
                else
                {
                    DEB((*mas + i)->group)
                    (buf + k)->group = (*mas + j)->group;
                    (buf + k)->surname = (*mas + j)->surname;
                    (buf + k)->marks = (*mas + j)->marks;
                    (buf + k)->q_marks = (*mas + j)->q_marks;
                    (buf + k)->birthday = (*mas + j)->birthday;
                    j++;
                    k++;
                }
            }
            while (i < step)
            {
                DEB((*mas + i)->group)
                // Переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                (buf + k)->group = (*mas + i)->group;
                (buf + k)->surname = (*mas + i)->surname;
                (buf + k)->marks = (*mas + i)->marks;
                (buf + k)->q_marks = (*mas + i)->q_marks;
                (buf + k)->birthday = (*mas + i)->birthday;
                i++;
                k++;
            }
            while ((j < (mid + step)) && (j < quan))
            {
                DEB((*mas + i)->group)
                // Переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                (buf + k)->group = (*mas + j)->group;
                (buf + k)->surname = (*mas + j)->surname;
                (buf + k)->marks = (*mas + j)->marks;
                (buf + k)->q_marks = (*mas + j)->q_marks;
                (buf + k)->birthday = (*mas + j)->birthday;
                j++;
                k++;
            }
            step = step + h; // Переходим к следующему этапу
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        for (i = 0; i < quan; i++)
        {
            (*mas + i)->group = (buf + i)->group;
            (*mas + i)->surname = (buf + i)->surname;
            (*mas + i)->marks = (buf + i)->marks;
            (*mas + i)->q_marks = (buf + i)->q_marks;
            (*mas + i)->birthday = (buf + i)->birthday;
        }
    }
    free(buf);
    return SUCCESS;
}

int sort_by_key(char *key, students **mas, int quan)
{
    if (quan <= 1)
        return SBK_DATA_ERROR;

    int (*comp)(students *, students *);

    if (!strcmp(key, "GROUP"))
        comp = comp_students_group;
    else if (!strcmp(key, "SURNAME"))
        comp = comp_students_surname;
    else if (!strcmp(key, "GRADE"))
        comp = comp_students_marks;
    else
        return SBK_KEY_ERROR;

    int check = merge_sort_students(mas, quan, comp);

    if (check)
        return check;

    return SUCCESS;
}


