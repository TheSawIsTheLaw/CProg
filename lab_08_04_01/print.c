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

/**
 * \fn short print_double_array(double const *const mas, int const quantity)
 *
 * \param double const *const mas - Указатель на динамический массив
 * \param int const quantity - Переменная размерности массива
 *
 * \brief Функция, выводящая переданный в неё массив
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения (нуль)
 */
short print_double_array(double const *const mas, int const quantity)
{
    if (!mas || quantity <= 0)
        return PDA_DATA_ERROR;

    for (int i = 0; i < quantity; i++)
        printf("%.6lf ", *(mas + i));
    return 0;
}
