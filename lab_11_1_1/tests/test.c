#include "tests.h"
#include <limits.h>

#define POS_TESTS 4
#define NEG_TESTS 3

int main(void)
{
    int neg = 0;

    if (neg_d_buf())
        neg++;
    else
        printf("Fault! 1\n\n");

    if (neg_d_format())
        neg++;
    else
        printf("Fault! 2\n\n");

    if (neg_d_size())
        neg++;
    else
        printf("Fault! 3\n\n");

    int pos = 0;
    if (pos_d_neg_num())
        pos++;
    else
        printf("Fault! 4");

    if (pos_d_normal())
        pos++;
    else
        printf("Fault! 5");

    if (pos_d_pos_num())
        pos++;
    else
        printf("Fault! 6");

    if (pos_d_text())
        pos++;
    else
        printf("Fault! 7");

    if (pos_d_zero_num())
        pos++;
    else
        printf("Fault! 8");

    char buf_f[30] = { 0 }, buf_s[30] = { 0 };

    int check_f = snprintf(buf_f, 20, "%x", UINT32_MAX + 2);

    int check_s = my_snprintf(buf_s, 20, "%x", UINT32_MAX + 2);

    if (check_f != check_s || strcmp(buf_f, buf_s))
        return FUUUUU;

    check_f = snprintf(buf_f, 20, "%x", 0);

    check_s = my_snprintf(buf_s, 20, "%x", 0);

    if (check_f != check_s || strcmp(buf_f, buf_s))
        return FUUUUU;

    check_f = snprintf(buf_f, 20, "%lx", UINT64_MAX);

    check_s = my_snprintf(buf_s, 20, "%lx", UINT64_MAX);

    if (check_f != check_s || strcmp(buf_f, buf_s))
        return FUUUUU;

    check_f = snprintf(buf_f, 20, "%lx", UINT64_MAX + 1);

    check_s = my_snprintf(buf_s, 20, "%lx", UINT64_MAX + 1);

    if (check_f != check_s || strcmp(buf_f, buf_s))
        return FUUUUU;

    check_f = snprintf(buf_f, 20, "%ld", INT64_MAX);

    check_s = my_snprintf(buf_s, 20, "%ld", INT64_MAX);

    if (check_f != check_s || strcmp(buf_f, buf_s))
        return FUUUUU;

    check_f = snprintf(buf_f, 21, "%ld", INT64_MIN);

    check_s = my_snprintf(buf_s, 21, "%ld", INT64_MIN);

    if (check_f != check_s || strcmp(buf_f, buf_s))
        return FUUUUU;

    int64_t a = 0;
    check_f = snprintf(buf_f, 21, "%ld", a);

    check_s = my_snprintf(buf_s, 21, "%ld", 0);

    if (check_f != check_s || strcmp(buf_f, buf_s))
        return FUUUUU;

    check_f = snprintf(buf_f, 20, "%li", INT64_MAX);

    check_s = my_snprintf(buf_s, 20, "%li", INT64_MAX);

    if (check_f != check_s || strcmp(buf_f, buf_s))
        return FUUUUU;

    check_f = snprintf(buf_f, 21, "%li", INT64_MIN);

    check_s = my_snprintf(buf_s, 21, "%ii", INT64_MIN);

    if (check_f != check_s || strcmp(buf_f, buf_s))
        return FUUUUU;

    check_f = snprintf(buf_f, 21, "%li", a);

    check_s = my_snprintf(buf_s, 21, "%li", 0);

    if (check_f != check_s || strcmp(buf_f, buf_s))
        return FUUUUU;

    //check_s = my_snprintf(buf_s, 20, "%li", INT64_MAX + 1);
    //check_s = my_snprintf(buf_s, 20, "%ld", INT64_MAX + 1);
    //check_s = my_snprintf(buf_s, 20, "%i", INT32_MAX + 1);
    //check_s = my_snprintf(buf_s, 20, "%d", INT32_MAX + 1);

    if (pos == POS_TESTS && neg == NEG_TESTS)
        return YAHOOO;
    else
        return FUUUUU;
}
