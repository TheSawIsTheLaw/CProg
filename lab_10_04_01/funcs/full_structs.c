#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/base.h"

#define SUCCESS 0
// Начальный размер массива записей
#define MAX 1
#define MAX_GR 10
#define MAX_SURN 20
#define MAX_BIRTH 3
#define MAX_MARKS 10

#define CODE_CHAR 48
#define CODE_SPACE 38

#define FS_CHECK_ERROR 100
#define FS_NILL_ERROR 101
#define FS_MEMORY_ERROR 102
#define FS_SCANF_ERROR 103

int full_structs(students **mas, FILE *f, int *out_quan)
{
    if (!mas)
        return FS_NILL_ERROR;

    unsigned long max_quant = MAX, real_mas_quant = 0;

    students *new = realloc(*mas, max_quant * sizeof (students));
    if (new)
    {
        *mas = new;
        new = NULL;
    }
    else
        return FS_MEMORY_ERROR;
    // Если в массиве не будет хватать места (по признаку того, что последний элемент != /0,
    // то в соотвествии с этим признаком каждый раз будет реаллокать +10, пока не хватит)

    // Переменные максимального количества значений
    int mq_gr = MAX_GR, mq_surn = MAX_SURN, mq_marks = MAX_MARKS;

    char *gr = calloc(MAX_GR, sizeof(char));
    char *surn = calloc(MAX_SURN, sizeof(char));

    // Это единственный массив, который меняться в размерах не будет.
    // Почему не статика? Нам запретили улыбаться и всячески радоваться жизни.
    // Neperevodimaya igra slov
    int *birth = calloc(MAX_BIRTH, sizeof(int));
    float *marks = calloc(MAX_MARKS, sizeof(float));

    if (!gr || !surn || !birth || !marks)
        return FS_MEMORY_ERROR;

    // Сосканфить стринг не получится. Потому что динамика... Придётся всё делать поэлементно.

    char cur_c = 'a';

    short flag = 1;
    int check, cur_pos, new_mq_marks;
    float *new_i_m;

    char* new_c;  // Переменная для расширения массивов char типа

    while (flag)
    {
        /// ! Работа с полем группы
        /// ! Work with group field
        DEB("GROUP STARTED")
        check = fscanf(f, "%c", &cur_c);
        if (check != 1)
        {
            free(gr);
            free(surn);
            free(birth);
            free(marks);

            return FS_SCANF_ERROR;
        }
        cur_pos = 0;
        while (cur_c != '\n' || cur_pos == 0)
        {
            while (cur_c == '\n' || cur_c == ' ')
            {
                check = fscanf(f, "%c", &cur_c);
                if (check != 1)
                {
                    free(gr);
                    free(surn);
                    free(birth);
                    free(marks);

                    return FS_SCANF_ERROR;
                }
            }
            gr[cur_pos] = cur_c;
            if (cur_pos == mq_gr - 1)
            {
                mq_gr = mq_gr * 2;
                new_c = realloc(gr, mq_gr * sizeof(char));
                if (new_c)
                {
                    gr = new_c;
                    new_c = NULL;
                }
                else
                {
                    free(gr);
                    free(surn);
                    free(birth);
                    free(marks);

                    return FS_MEMORY_ERROR;
                }
            }
            cur_pos++;
            check = fscanf(f, "%c", &cur_c);
            if (check != 1)
            {
                free(gr);
                free(surn);
                free(birth);
                free(marks);

                return FS_SCANF_ERROR;
            }
        }
        if (cur_pos == mq_gr - 1)
        {
            mq_gr = mq_gr + 1;
            new_c = realloc(gr, mq_gr * sizeof(char));
            if (new_c)
            {
                gr = new_c;
                new_c = NULL;
            }
            else
            {
                free(gr);
                free(surn);
                free(birth);
                free(marks);
                return FS_MEMORY_ERROR;
            }
        }
        gr[cur_pos] = '\0';

        /// ! Проверка на то, является ли это стоп-словом (простите, это не отсылка)
        /// ! Checking flag for stop "whiling" (rolling-rolling-rolling, c'mon)
        DEB(gr)
        if (!strcmp("none", gr))
        {
            flag = 0; // Да, это смешно. Но мне бы иначе сказали, что у меня цикл бесконечный. Ага.

            break;
        }

        DEB("SURNAME STARTED")
        check = fscanf(f, "%c", &cur_c);
        if (check != 1)
        {
            free(gr);
            free(surn);
            free(birth);
            free(marks);

            return FS_SCANF_ERROR;
        }
        cur_pos = 0;

        /// ! Работа с полем имени
        /// ! Work with surname field
        while (cur_c != '\n' || !cur_pos)
        {
            if (cur_pos == mq_surn - 1)
            {
                mq_surn = mq_surn * 2;

                new_c = realloc(surn, mq_surn * sizeof(char));

                if (new_c)
                {
                    surn = new_c;
                    new_c = NULL;
                }
                else
                {
                    free(gr);
                    free(surn);
                    free(birth);
                    free(marks);

                    return FS_MEMORY_ERROR;
                }
            }
            surn[cur_pos] = cur_c;
            cur_pos++;

            check = fscanf(f, "%c", &cur_c);
            if (check != 1)
            {
                free(gr);
                free(surn);
                free(birth);
                free(marks);

                return FS_SCANF_ERROR;
            }
        }
        if (cur_pos == mq_surn - 1)
        {
            mq_surn = mq_surn * 2;

            new_c = realloc(surn, mq_surn * sizeof(char));

            if (new_c)
            {
                surn = new_c;
                new_c = NULL;
            }
            else
            {
                free(gr);
                free(surn);
                free(birth);
                free(marks);

                return FS_MEMORY_ERROR;
            }
        }
        surn[cur_pos] = '\0';
        DEB(surn)

        /// ! Работа с полем датой рождения
        /// ! ALARM! На данном этапе отладка с восприятием 31-го февраля не произведена!
        /// ! Work with birthday field
        DEB("BIRTHDAY STARTED")
        check = fscanf(f, "%d.%d.%d", birth, birth + 1, birth + 2);
        if (check != 3)
        {
            free(gr);
            free(surn);
            free(birth);
            free(marks);

            return FS_SCANF_ERROR;
        }
        /// !
        /// ! ТУТ МОГЛА БЫТЬ ВАША РЕКЛАМА (ИЛИ ПРОВЕРКА)
        /// !

        /// ! Работа с полем оценок
        /// ! Work with marks field
        DEB("MARKS STARTED")
        check = fscanf(f, "%d", &new_mq_marks);
        if (check != 1)
        {
            free(gr);
            free(surn);
            free(birth);
            free(marks);

            return FS_SCANF_ERROR;
        }
        if (new_mq_marks > mq_marks)
        {
            mq_marks = new_mq_marks;
            new_i_m = realloc(marks, mq_marks * sizeof(float));
            if (new_i_m)
            {
                marks = new_i_m;
                new_i_m = NULL;
            }
            else
            {
                free(gr);
                free(surn);
                free(birth);
                free(marks);

                return FS_MEMORY_ERROR;
            }
        }
        float new_marks;
        for (int i = 0; i < new_mq_marks; i++)
        {
            check = fscanf(f, "%f", &new_marks);
            if (check != 1)
            {
                free(gr);
                free(surn);
                free(birth);
                free(marks);

                return FS_SCANF_ERROR;
            }
            marks[i] = new_marks;
        }
        DEB("MARKS ENDED")

        /// !
        /// ! Дальше вообще начинается лютый треш и содомия, приготовьтесь
        /// !
        /// ! Send new fields to structure and it's ?reallocation?
        /// !

        DEB("SENDING...")

        // Group
        (*mas + real_mas_quant)->group = calloc(mq_gr, sizeof(char));
        if (!((*mas + real_mas_quant)->group))
        {
            free(gr);
            free(surn);
            free(birth);
            free(marks);

            return FS_MEMORY_ERROR;
        }
        strcpy((*mas + real_mas_quant)->group, gr);

        // Surname
        (*mas + real_mas_quant)->surname = calloc(mq_surn, sizeof(char));
        if (!((*mas + real_mas_quant)->surname))
        {
            free(gr);
            free(surn);
            free(birth);
            free(marks);

            //free((*mas + real_mas_quant)->group);

            return FS_MEMORY_ERROR;
        }
        strcpy((*mas + real_mas_quant)->surname, surn);

        // Birthday
        (*mas + real_mas_quant)->birthday = calloc(MAX_BIRTH, sizeof(int));
        if (!((*mas + real_mas_quant)->birthday))
        {
            free(gr);
            free(surn);
            free(birth);
            free(marks);

            free((*mas + real_mas_quant)->group);
            free((*mas + real_mas_quant)->surname);

            return FS_MEMORY_ERROR;
        }

        *((*mas + real_mas_quant)->birthday) = birth[0];
        *((*mas + real_mas_quant)->birthday + 1) = birth[1];
        *((*mas + real_mas_quant)->birthday + 2) = birth[2];

        // Marks
        (*mas + real_mas_quant)->q_marks = new_mq_marks;

        (*mas + real_mas_quant)->marks = calloc(new_mq_marks, sizeof(float));
        if (!((*mas + real_mas_quant)->marks))
        {
            free(gr);
            free(surn);
            free(birth);
            free(marks);

            free((*mas + real_mas_quant)->group);
            free((*mas + real_mas_quant)->surname);

            return FS_MEMORY_ERROR;
        }
        for (int i = 0; i < new_mq_marks; i++)
            *((*mas + real_mas_quant)->marks + i) = marks[i];
        real_mas_quant++;

        max_quant++; // Топорно, но уж лучше реаллокать, чем таскать за собой длину массива структур
        new = realloc(*mas, max_quant * sizeof(students));
        if (new)
        {
            *mas = new;
            new = NULL;
        }
        else
        {
            free(gr);
            free(surn);
            free(birth);
            free(marks);

            free((*mas + real_mas_quant)->group);
            free((*mas + real_mas_quant)->surname);
            free((*mas + real_mas_quant)->birthday);

            return FS_MEMORY_ERROR;
        }
    }

    // В конце следует добавить конечное поле с none, чтобы иметь понятие, где оное кончается
    (*mas + real_mas_quant)->group = calloc(5, sizeof(char));
    if (!((*mas + real_mas_quant)->group))
    {
        free(gr);
        free(surn);
        free(birth);
        free(marks);

        return FS_MEMORY_ERROR;
    }
    strcpy((*mas + real_mas_quant)->group, "none");

    free(gr);
    free(surn);
    free(birth);
    free(marks);

    *out_quan = real_mas_quant;

    return SUCCESS;
}

