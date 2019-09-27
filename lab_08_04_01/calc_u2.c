#include <stdio.h>
#include <math.h>
#include "Headers/calc_u2.h"

/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0
/**
 * \def C_U2_DATA_ERROR
 * \brief Код ошибки в подпрограмме calc_u2
 */
#define C_U2_DATA_ERROR 7

short calc_u2(int const quantity, double *mas, double *const u2)
{
    if (quantity <= 0 || !mas || !u2)
        return C_U2_DATA_ERROR;

    double sum = 0;
    for (int i = 0; i < quantity; i++)
        sum += *(mas + i) / quantity;

    *u2 = sum;

    return SUCCESS;
}