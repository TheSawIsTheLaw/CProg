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

/**
 * \fn short del_from_mas_upmod_num(double **const mas, int *const quantity, double const num)
 *
 * \param int *const quantity - Указатель на переменную размерности массива
 * \param double **const mas - Указатель на указатель на динамический массив
 * \param double const num - число-фактор удаления
 *
 * \brief Функция, удаляющая все числа из массива, модуль которых выше
 * переданного числа-фактора
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения (нуль)
 */
short del_from_mas_upmod_num(double **const mas, int *const quantity, double const num)
{
    if (!(mas) || !(*mas) || !quantity || *quantity <= 0 || num <= 0)
        return DFMUN_DATA_ERROR;

    for (int i = 0; i < *quantity; i++)
    {
        if (fabs(*(*mas + i)) > num)
        {
            (*quantity)--;
            // Массив получается пустым, закрыть ворота!
            if (*quantity <= 0)
                return DFMUN_QUANTITY_OUT_ERROR;
            for (int j = i; j < *quantity; j++)
                *(*mas + j) = *(*mas + j + 1);
            *mas = (double *)realloc(*mas, sizeof(double) * (*quantity));
            if (!(*mas))
                return DFMUN_REALLOC_ERROR;
            i--;
        }
    }
    return SUCCESS;
}
