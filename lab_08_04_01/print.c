#include <stdio.h>
#include "Headers/print.h"

/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0
/**
 * \def PDA_DATA_ERROR
 * \brief Код ошибки в подпрограмме print_double_array
 */
#define PDA_DATA_ERROR 13

short print_double_array(double *mas, int const quantity)
{
    if (!mas || quantity <= 0)
        return PDA_DATA_ERROR;

    for (int i = 0; i < quantity; i++)
        printf("%.6lf ", *(mas + i));
    return 0;
}