#include <stdio.h>
#include <stdlib.h>
#include "Headers/invitation.h"

/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0
/**
 * \def QUANTITY_ERROR
 * \brief Код ошибки в подпрограмме invitation_len_mas_pos
 */
#define QUANTITY_ERROR 1
/**
 * \def READ_ARRAY_ERROR
 * \brief Код ошибки в подпрограмме expand_dyn_mas
 */
#define READ_ARRAY_ERROR 3
/**
 * \def POS_ERROR
 * \brief Код ошибки в подпрограмме invitation_len_mas_pos
 */
#define POS_ERROR 4

short invitation_len_mas_pos(int const quantity, double **mas, int *const pos)
{
    // Тут проверок не будет. С разыменованием наступает ад и Израиль.
    if (!pos)
        return QUANTITY_ERROR;

    *mas = (double *)calloc(quantity, sizeof(double));
    if (!(*mas))
        return QUANTITY_ERROR;

    short check;
    for (int i = 0; i < quantity; i++)
    {
        check = scanf("%lf", *mas + i);
        if (!check)
            return READ_ARRAY_ERROR;
    }

    check = scanf("%d", pos);

    if (!check || *pos < 0)
        return POS_ERROR;

    return SUCCESS;
}
