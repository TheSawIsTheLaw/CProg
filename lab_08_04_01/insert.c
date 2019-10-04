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

/**
 * \fn short insert_in_mas_by_pos_start_end(double **const mas, int *const quantity,
 * int const pos, double const num)
 *
 * \param double **const mas - Указатель на указатель на динамический массив
 * \param int *const quantity - Указатель на переменную размерности массива
 * \param int const pos - Позиция вставки помимо начала и конца
 * \param double const num - вставляемое число
 *
 * \brief Функция, вставляющая переданное в неё число в начало, конец и
 * заданную позицию массива
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения (нуль)
 */
short insert_in_mas_by_pos_start_end(double **const mas, int *const quantity,
int const pos, double const num)
{
    if (!mas || !(*mas) || !quantity || *quantity < 1 || *quantity < pos + 1 || pos < 0)
        return IIMBPSE_DATA_ERROR;
    // Добавление места под элементы
    *quantity = *quantity + 3;
    *mas = (double *)realloc(*mas, sizeof(double) * (*quantity));
    if (!(*mas))
        return IIMBPSE_REALLOC_ERROR;

    // Сдвиг
    for (int i = *quantity - 3; i > 0; i--)
        *(*mas + i) = *(*mas + i - 1);
    **mas = num;

    // Сдвиг
    for (int i = *quantity - 2; i > pos + 1; i--)
        *(*mas + i) = *(*mas + i - 1);
    *(*mas + pos + 1) = num;
    *(*mas + *quantity - 1) = num;
    return SUCCESS;
}
