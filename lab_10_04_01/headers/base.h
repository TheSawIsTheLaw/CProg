#ifndef __BASE_H__
#define __BASE_H__

typedef struct
{
    char *group;
    char *surname;
    int *birthday;
    int q_marks;
    int *marks;
}students;

int free_students();

int full_structs();

int kill_adults();

int kill_lower_four_marks();

int print_info();

int sort_by_key();

#endif
