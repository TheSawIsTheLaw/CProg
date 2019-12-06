#include "../tests.h"

int pos_d_zero_num()
{
    char buf_f[10] = { 0 }, buf_s[10] = { 0 };

    int check_f = snprintf(buf_f, 10, "%d %d %d", 0, 0, 0);
    DEB(check)

    int check_s = my_snprintf(buf_s, 10, "%d %d %d", 0, 0, 0);
    DEB(check)

    DEB(strcmp(buf_f, buf_s))

    if (strcmp(buf_f, buf_s) == 0 && check_f == check_s)
        return YAHOOO;
    else
        return FUUUUU;
}
