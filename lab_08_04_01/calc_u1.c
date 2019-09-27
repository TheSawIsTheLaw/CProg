#include <stdio.h>
#include <math.h>
#include "Headers/calc_u1.h"

/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0
/**
 * \def C_U1_DATA_ERROR
 * \brief Код ошибки в подпрограмме calc_u1
 */
#define C_U1_DATA_ERROR 6

short calc_u1(int const quantity, double *mas, double *const u1)
{
    if (quantity <= 0 || !mas || !u1)
        return C_U1_DATA_ERROR;

    double sum = 0;
    int sum_del = 0;
    for (int i = 0; i <= quantity - 1; i++)
    {
        sum_del += (i + 1) * (i + 1);
        sum += (i + 1) * (i + 1) * (*(mas + i));
    }
    *u1 = sum / sum_del;

    return SUCCESS;
}
