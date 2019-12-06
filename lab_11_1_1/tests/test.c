#include "tests.h"

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

    if (pos == POS_TESTS && neg == NEG_TESTS)
        return YAHOOO;
    else
        return FUUUUU;
}
