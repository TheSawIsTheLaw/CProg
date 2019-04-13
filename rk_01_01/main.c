/* Даны два числа записанные в массивах. Найти сумму двух чисел, поместить
 * в новый массив.
 */
#include <stdio.h>

int fin(int *p, int *a, int *b, int len)
{
    for (int i = 0; i < len; i++)
    {
        *(p + i) = *(a + i) + *(b+i);
    }

    return 0;
}

int main(void)
{
    printf("Inp Len ");
    int rc, len;
    rc = scanf("%d", &len);
    if (rc != 1 || len <= 0)
    {
        printf("Error!");

        return 1;
    }
    int A[len], B[len];
    printf("First mas  ");
    for (int i = 0; i < len; i++)
        scanf("%d", &A[i]);
    printf("Second mas ");
    for (int i = 0; i < len; i++)
        scanf("%d", &B[i]);
    int goty[len];
    int *p, *a, *b;
    p = &goty[0];
    a = &A[0];
    b = &B[0];
    fin(p, a, b, len);
    printf("Final mas ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", goty[i]);
    }
}
