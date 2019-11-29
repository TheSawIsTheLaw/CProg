#ifndef __BASE_H__
#define __BASE_H__
#define DEBUG 0

#if DEBUG == 1
#define DEB(s) printf("\nDEBUGGING_VALUE\n%s\nEND_DEB\n",s);
#elif DEBUG == 0
#define DEB(s) {};
#endif

typedef struct
{
    char *group;
    char *surname;
    int *birthday;
    int q_marks;
    float *marks;
}students;

int free_students();

int full_structs();

int kill_adults();

int kill_lower_four_marks();

int print_info();

int sort_by_key();

#endif
