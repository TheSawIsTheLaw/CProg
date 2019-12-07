#include "../tests.h"

int neg_d_buf()
{
    int check_f = my_snprintf(NULL, 30, "death\n %d sounds like", 0);
    DEB(check_f)

    if (check_f == 20)
        return YAHOOO;
    else
        return FUUUUU;
}
