#include <stdio.h>
#include <string.h>
#include "../my_snprintf.h"
#include "tests.h"

int main(void)
{
    char buf_f[30] = { 0 }, buf_s[30] = { 0 };

    snprintf(buf_f, 30, "%d", 0);

    my_snprintf(buf_s, 30, "%d", 0);

    printf("%s %s\n", buf_f, buf_s);

    printf("strcmp %d\n", strcmp(buf_f, buf_s));

    snprintf(buf_f, 30, "%d %d %d", 1, 2, 3);

    my_snprintf(buf_s, 30, "%d %d %d", 1, 2, 3);

    printf("%s %s\n", buf_f, buf_s);

    printf("strcmp %d\n", strcmp(buf_f, buf_s));

    snprintf(buf_f, 2, "%d", 1);

    my_snprintf(buf_s, 2, "%d", 1);

    printf("%s %s\n", buf_f, buf_s);

    printf("strcmp %d\n", strcmp(buf_f, buf_s));

    snprintf(buf_f, 30, "%d %d", -6663336, 6663336);

    my_snprintf(buf_s, 30, "%d %d", -6663336, 6663336);

    printf("%s %s\n", buf_f, buf_s);

    printf("strcmp %d\n", strcmp(buf_f, buf_s));




    snprintf(buf_f, 30, "%i %i", 500, 512);

    my_snprintf(buf_s, 30, "%i %i", 500, 512);

    printf("%s %s\n", buf_f, buf_s);

    printf("strcmp %d\n", strcmp(buf_f, buf_s));

    return 0;
}
