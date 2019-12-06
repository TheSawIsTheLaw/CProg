#include "../tests.h"

int neg_d_buf()
{
    int check_f = my_snprintf(NULL, 30, "death\n %d sounds like", 0);
    DEB(check_f)

    DEB(strcmp(buf_f, buf_s))

    if (!check_f)
        return YAHOOO;
    else
        return FUUUUU;
}
