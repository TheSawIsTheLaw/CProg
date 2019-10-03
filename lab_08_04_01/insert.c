#include <stdio.h>
#include <stdlib.h>
#include "Headers/insert.h"

/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0
/**
 * \def IIMBPSE_DATA_ERROR
 * \brief Код ошибки в подпрограмме insert_in_mas_by_pos_start_end
 */
#define IIMBPSE_DATA_ERROR 11
/**
 * \def IIMBPSE_REALLOC_ERROR
 * \brief Код ошибки в подпрограмме insert_in_mas_by_pos_start_end
 */
#define IIMBPSE_REALLOC_ERROR 12

short insert_in_mas_by_pos_start_end(double **mas, int *const quantity,
                                     int const pos, double const num)
{
    if (!(*mas) || !quantity || pos >= *quantity || pos < 0)
    {
        printf("\n ЭТА ХУЙНЯ БЛЯТЬ ЗАРЯЖЕН В КИОСКЕ %d %d", pos, *quantity);
        return IIMBPSE_DATA_ERROR;
    }
    *quantity = *quantity + 3;
    *mas = (double *)realloc(*mas, sizeof(double) * (*quantity));
    if (!(*mas))
        return IIMBPSE_REALLOC_ERROR;

    for (int i = *quantity - 3; i > 0; i--)
        *(*mas + i) = *(*mas + i - 1);
    **mas = num;

    for (int i = *quantity - 2; i > pos + 1; i--)
        *(*mas + i) = *(*mas + i - 1);
    *(*mas + pos + 1) = num;
    *(*mas + *quantity - 1) = num;
    return SUCCESS;
}
