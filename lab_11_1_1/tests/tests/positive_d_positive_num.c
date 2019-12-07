#include "../tests.h"

int pos_d_pos_num()
{
    char buf_f[30] = { 0 }, buf_s[30] = { 0 };

    int check_f = snprintf(buf_f, 30, "death\n %d%d sounds like", 666, 700);
    DEB(check_f)

    int check_s = my_snprintf(buf_s, 30, "death\n %d%d sounds like", 666, 700);
    DEB(check_s)

    DEB(strcmp(buf_f, buf_s))

    if (strcmp(buf_f, buf_s) == 0 && check_f == check_s)
        return YAHOOO;
    else
        return FUUUUU;
}
