#include "../tests.h"

int neg_d_format()
{
    char buf_f[1] = { 0 };
    int check_f = my_snprintf(buf_f, 30, NULL, 0);
    DEB(check_f)

    if (check_f == -1)
        return YAHOOO;
    else
        return FUUUUU;
}
