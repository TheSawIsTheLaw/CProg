#include "../tests.h"

int neg_d_format()
{
    char buf_f[1] = { 0 };
    int check_f = my_snprintf(buf_f, 30, NULL, 0);
    DEB(check_f)

    DEB(strcmp(buf_f, buf_s))

    if (!check_f)
        return YAHOOO;
    else
        return FUUUUU;
}
