#include "../tests.h"

int pos_d_normal()
{
    char buf_f[30] = { 0 }, buf_s[30] = { 0 };

    int check_f = snprintf(buf_f, 30, "%d %d %d %d", 1, 700, -666, 200);
    DEB(check_f)

    int check_s = my_snprintf(buf_s, 30, "%d %d %d %d", 1, 700, -666, 200);
    DEB(check_f)

    DEB(strcmp(buf_f, buf_s))

    if (strcmp(buf_f, buf_s) == 0 && check_f == check_s)
        return YAHOOO;
    else
        return FUUUUU;
}
