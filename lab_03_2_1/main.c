/**
 * \file main.c
 * \brief Пользователь вводит целые числа, по окончании ввода
 * чисел вводит букву (в Windows для ввода в окне cmd признака
 * EOF можно нажать Ctrl-Z и Enter).
 * Находит порядковый номер максимального из чисел (если чисел
 * с максимальным значением несколько, то должен быть найден
 * номер первого из них);
 * При решении любой задачи из варианта 1 два цикла ввода и
 * массивы не использовать.
 *
 * Коды ошибок:
 *
 * -1 - файла не существует или доступ к нему отсутствует;
 * 
 * -2 - в функции find_max_in_row оказалось, что переданного
 * файла не существует или доступ к нему отсутствует;
 * 
 * -3 - переменной не было присвоено значение;
 */

#include <stdio.h>

/**
 * \def ZERO
 * \brief Ok code or just a number
 */
#define ZERO 0
/**
 * \def ONE
 * \brief Just a number
 */
#define ONE 1
/**
 * \def FILE_ERROR
 * \brief Error code
 */
#define FILE_ERROR -1
/**
 * \def IN_FUNC_FILE_ERROR
 * \brief Error code
 */
#define IN_FUNC_FILE_ERROR -2
/**
 * \def IN_FUNC_SCAN_ERROR
 * \brief Error code
 */
#define IN_FUNC_SCAN_ERROR -3

/**
 * \fn int find_max_in_row(FILE *in, int *const index)
 * \brief Функция находит индекс максимального числа из
 * введённых величин. Индексация начинается с единицы.
 *
 * \param [out] in Файловая переменная
 * \param [out] index Адрес, по которому будет записан индекс
 * \return Код ошибки или успешного завершения
 */
int find_max_in_row(FILE *const in, int *const index)
{
    if (!in)
        return IN_FUNC_FILE_ERROR;
    int q, i = ONE, ind = ONE,
        n = fscanf(in, "%d", &q);
    if (n != ONE)
        return IN_FUNC_SCAN_ERROR;
    int max = q;
    while (n == ONE)
    {
        if (q > max)
        {
            ind = i;
            max = q;
        }
        n = fscanf(in, "%d", &q);
        i++;
    }
    *index = ind;
    return ZERO;
}

int main(void)
{
    FILE *in = stdin;
    if (!in)
        return FILE_ERROR;
    int index = ZERO,
        n = find_max_in_row(in, &index);
    if (n)
        return n;
    else
        printf("%d", index);
    return 0;
}