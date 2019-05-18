/* Дано число N. Определить какие из двух рядом стоящих цифр в нем
 *  являются простым числом.
 */

#include <stdio.h>

int findmaxp(int number)
{
    long long int max = 1;
    while (max < number)
        max = max * 10;
    max = max / 100;
    return max;
}

int isprost(int numb)
{
    if (numb == 1)
        return 0;
    int deli = 2;
    while (numb % deli != 0)
    {
        deli += 1;
    }
    if (deli == numb)
        return 1;
    else
        return 0;
}

int main(void)
{
    printf("Inp number ");
    int number, max;
    scanf("%d", &number);
    if (number < 0)
        number = number * -1;
    max = findmaxp(number);
    int rab;
    while (max > 0)
    {
        rab = number / max;
        rab = rab % 100;
        if (isprost(rab) == 1)
            printf("%d ", rab);
        max = max / 10;
    }
    return 0;
}
