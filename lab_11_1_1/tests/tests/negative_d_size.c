#include <limits.h>
#include "../tests.h"

int neg_d_size()
{
    char buf_f[3] = { 0 };
    int check_f = my_snprintf(buf_f, (size_t)INT_MAX + 1, "%d ", 0);
    DEB(check_f)

    if (check_f == -1)
        return YAHOOO;
    else
        return FUUUUU;
}
