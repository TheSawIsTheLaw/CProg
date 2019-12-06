#include "../tests.h"

int pos_d_text()
{
    char buf_f[45] = { 0 }, buf_s[45] = { 0 };

    int check_f = snprintf(buf_f, 30, "%d death%d death%ddeath death%d%ddeath", 666, 666, 666, 666, 666);
    DEB(check)

    int check_s = my_snprintf(buf_s, 30, "%d death%d death%ddeath death%d%ddeath", 666, 666, 666, 666, 666);
    DEB(check)

    DEB(strcmp(buf_f, buf_s))

    if (strcmp(buf_f, buf_s) == 0 && check_f == check_s)
        return YAHOOO;
    else
        return FUUUUU;
}
