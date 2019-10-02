#include <stdio.h>
#include <stdlib.h>
#include "Headers/expand.h"
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
 * \def POS_ERROR
 * \brief Код ошибки в подпрограмме invitation_len_mas_pos
 */
#define POS_ERROR 4

short invitation_len_mas_pos(int *const quantity, double **mas, int *const pos)
{
    short check;

    check = scanf("%d", quantity);
    if (!check)
        return QUANTITY_ERROR;

    *mas = (double *)malloc(sizeof(double));
    if (!(*mas))
        return QUANTITY_ERROR;

    check = expand_dyn_mas(*quantity, mas);

    if (check)
        return check;

    check = scanf("%d", pos);

    if (!check)
        return POS_ERROR;

    return SUCCESS;
}