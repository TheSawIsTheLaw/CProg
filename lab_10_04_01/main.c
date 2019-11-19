/**
 * \file main.с
 * \brief Лабораборная работа номер 10.
 * Вариант 4.
 * Задание:
 * О каждом студенте известны группа, фамилия, дата рождения и оценки за предыдущий семестр. Обрабатывая данные о наборе студентов в виде массива записей,
 * требуется:
 * (a) Принять с клавиатуры данные о наборе студентов. Признаком окончания ввода
 * считается группа «none». Формат ввода:
 * ∙ Каждое поле вводится с новой строки.
 * ∙ Группа — набор символов в любом регистре.
 * ∙ Фамилия — набор символов латинского алфавита в любом регистре.
 * ∙ Дата рождения — строка вида YYYY.MM.DD.
 * ∙ Оценки за предыдущий семестр — количество оценок в виде целого числа
 * и сами оценки в виде действительных чисел, разделённых пробелами.
 * (b) Удалить из массива студентов группы ИУ7-31Б старше 17 лет. Текущей датой
 * считать первое ноября 2019 года.
 * (c) Удалить из оценок за семестр всех студентов оценки ниже 4.0.
 * (d) Приняв с клавиатуры один из ключей GROUP, SURNAME, GRADE, отсортировать
 * массив устойчиво по соответствующему ключу.
 * (e) Распечатать информацию о студентах в текстовый файл students.txt
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/base.h"

#define MEMORY_ERROR 666
#define SUCCESS 0

#define DEBUG

#ifdef DEBUG
#include <string.h>
#endif

// Задание файловых переменных для ввода/вывода
#define F_IN stdin
#define F_OUT stdout

int main(void)
{
    students *mas_s = calloc(1, sizeof(students));

    if (!mas_s)
        return MEMORY_ERROR;
#ifndef DEBUG
    FILE *f_out = F_OUT;
#endif
    FILE *f_in = F_IN;


    int check = full_structs(&mas_s, f_in);
    if (check)
    {
        free(mas_s);
        return check;
    }

#ifdef DEBUG
    int i = 0;
    while (strcmp((mas_s + i)->group, "none"))
    {
        printf("%s %s ", (mas_s + i)->group, (mas_s + i)->surname);
        printf("%d.%d.%d ", *((mas_s + i)->birthday), *((mas_s + i)->birthday + 1), *((mas_s + i)->birthday + 2));
        for (int j = 0; j < (mas_s + i)->q_marks; j++)
            printf("%d ", *((mas_s + i)->marks));
        i++;
    }
#endif
#ifndef DEBUG
    check = kill_adults();
    if (check)
    {
        free_students(&mas_s);
        return check;
    }

    check = kill_lower_four_marks();
    if (check)
    {
        free_students(&mas_s);
        return check;
    }

    check = sort_by_key();
    if (check)
    {
        free_students(&mas_s);
        return check;
    }

    check = print_info();
    if (check)
    {
        free_students(&mas_s);
        return check;
    }

    check = free_students(&mas_s);
    if (check)
        return check;
#endif

    return SUCCESS;
}
