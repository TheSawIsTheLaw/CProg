#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Headers/del.h"

/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0
/**
 * \def DFMUN_DATA_ERROR
 * \brief Код ошибки в подпрограмме del_from_mas_upmod_num
 */
#define DFMUN_DATA_ERROR 8
/**
 * \def DFMUN_QUANTITY_OUT_ERROR
 * \brief Код ошибки в подпрограмме del_from_mas_upmod_num
 */
#define DFMUN_QUANTITY_OUT_ERROR 9
/**
 * \def DFMUN_REALLOC_ERROR
 * \brief Код ошибки в подпрограмме del_from_mas_upmod_num
 */
#define DFMUN_REALLOC_ERROR 10

short del_from_mas_upmod_num(double *mas, int *const quantity, double const num)
{
    if ( !mas || !quantity || *quantity <= 0 || num <= 0)
        return DFMUN_DATA_ERROR;

    for (int i = 0; i < *quantity; i++)
    {
        if (fabs(*(mas + i)) > num)
        {
            (*quantity)--;
            if (*quantity <= 0)
                return DFMUN_QUANTITY_OUT_ERROR;
            for (int j = i; j < *quantity; j++)
                *(mas + j) = *(mas + j + 1);
            mas = (double*)realloc(mas, sizeof(double) * (*quantity));
            if (!mas)
                return DFMUN_REALLOC_ERROR;
            i--;
        }
    }
    return SUCCESS;
}