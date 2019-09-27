#include <stdio.h>
#include <stdlib.h>
#include "../Headers/expand.h"

/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0
/**
 * \def EDM_REALLOC_ERROR
 * \brief Код ошибки в подпрограмме expand_dyn_mas
 */
#define EDM_REALLOC_ERROR 2
/**
 * \def READ_ARRAY_ERROR
 * \brief Код ошибки в подпрограмме expand_dyn_mas
 */
#define READ_ARRAY_ERROR 3
/**
 * \def EDM_DATA_ERROR
 * \brief Код ошибки в подпрограмме expand_dyn_mas
 */
#define EDM_DATA_ERROR 5

short expand_dyn_mas(const int quantity, double *mas)
{
    if (quantity <= 0 || !mas)
        return EDM_DATA_ERROR;
    mas = (double*)realloc(mas, sizeof(double) * quantity);
    if (!mas)
        return EDM_REALLOC_ERROR;

    short check;
    for (int i = 0; i < quantity; i++)
    {
        check = scanf("%lf", mas + i);
        if (!check)
            return READ_ARRAY_ERROR;
    }

    return SUCCESS;
}