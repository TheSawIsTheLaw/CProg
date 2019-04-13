/* Дано число N. Определить какие из двух рядом стоящих цифр в нем
 *  являются простым числом.
 */

#include <stdio.h>

int findmaxp(int number)
{
    int max = 1;
    while (max < number)
        max = max * 10;
    max = max / 10;
    return max;
}

int isprost(int num)
{

}

int main(void)
{
    printf("Inp number ");
    int number;
    scanf("%d ", &number);
    if (number < 0)
        number = number * -1;
    max = findmaxp(number);
    int rab;
    while (max > 1)
    {
        rab = number / (max / 10);
        rab = rab % 100;
        if (isprost(rab) == 1)
            printf("%d ", rab);
    }
    return 0;
}
