/**
 * \file main.c
 * \brief Написать программу, которая считывает из текстового
 * файла вещественные числа и выполняет над ними некоторые
 * вычисления: найти среднее значение чисел, расположенных
 * между минимальным и максимальным числами («между» - не по
 * значению, а по расположению).
 *
 * Коды ошибок:
 *
 * -666 - В функцию переданы некорректные аргументы;
 *
 * -4 - Наибольшее и наименьшее число одно и то же;
 *
 * -3 - В функцию был передан некорректный индекс эл-та;
 *
 * -2 - Переменной не было прсивоено значение;
 */

#include <stdio.h>
#include <string.h>

/**
 * \def ARGS_ERROR
 * \brief В функцию переданы некорректные аргументы
 */
#define ARGS_ERROR -666
/**
 * \def EQ_INDEX
 * \brief Наибольшее и наименьшее число одно и то же
 */
#define EQ_INDEX -4
/**
 * \def INCORRECT_INDEX
 * \brief В функцию был передан некорректный индекс эл-та
 */
#define INCORRECT_INDEX -3
/**
 * \def FILE_ERROR
 * \brief Файла не существует или он недоступен
 */
#define FILE_ERROR -2
/**
 * \def SCAN_ERROR
 * \brief Переменной не было прсивоено значение
 */
#define SCAN_ERROR -1
/**
 * \def ZERO
 * \brief Код "Всё хорошо" или просто число
 */
#define ZERO 0
/**
 * \def ONE
 * \brief Просто число
 */
#define ONE 1
/**
 * \def TWO
 * \brief Просто число
 */
#define TWO 2

/**
 * \fn int find_ind_max(FILE *const in)
 * \brief Функция находит индекс максимального числа из
 * в файле
 *
 * \param [out] in Файловая переменная
 * \return Код ошибки или индекс требуемого элемента
 */
int find_ind_max(FILE *const in)
{
    if (!in)
        return FILE_ERROR;
    fseek(in, ZERO, SEEK_SET);
    float number;
    int n = fscanf(in, "%f", &number),
        i = ZERO, index = ZERO;
    if (!n)
        return SCAN_ERROR;
    float max = number;
    while (n == ONE)
    {
        if (number > max)
        {
            index = i;
            max = number;
        }
        n = fscanf(in, "%f", &number);
        i++;
    }
    return index;
}

/**
 * \fn int find_ind_min(FILE *const in)
 * \brief Функция находит индекс минимального числа из
 * в файле
 *
 * \param [out] in Файловая переменная
 * \return Код ошибки или индекс требуемого элемента
 */
int find_ind_min(FILE *const in)
{
    if (!in)
        return FILE_ERROR;
    fseek(in, ZERO, SEEK_SET);
    float number;
    int n = fscanf(in, "%f", &number),
        i = ZERO, index = ZERO;
    if (!n)
        return SCAN_ERROR;
    float min = number;
    while (n == ONE)
    {
        if (number < min)
        {
            index = i;
            min = number;
        }
        n = fscanf(in, "%f", &number);
        i++;
    }
    return index;
}

/**
 * \fn int find_average_between_indices(FILE *const in,
 *  int start, int end, float *const average)
 * \brief Функция находит индекс максимального числа из
 * в файле
 *
 * \param [out] in Файловая переменная
 * \param [out] start Начальный индекс расчёта
 * \param [out] end Конечный индекс расчёта
 * \param [out] average Адрес, куда записывается результат
 * \return Код ошибки или удачного совершения операции
 */
int find_average_between_indices(FILE *const in,
    int start, int end, float *const average)
{
    if (!in)
        return FILE_ERROR;
    if (start == end)
        return EQ_INDEX;
    else if (start > end)
    {
        float memory = end;
        end = start;
        start = memory;
    }
   /*
    * fseek(in, sizeof(float) * (start + 1), SEEK_SET);
    * А потом я вспомнил, что это не бинарный файл.
    * А ведь с такими идеями мог бы и в Google попасть!..
    */
    fseek(in, ZERO, SEEK_SET);
    float number;
    int n = fscanf(in, "%f", &number);
    if (!n)
        return SCAN_ERROR;
    float aver = ZERO;
    int quantity = ZERO, i = ONE;
    while (n == ONE && i < end + ONE)
    {
        if (i > start + ONE)
        {
            quantity++;
            aver += number;
        }
        n = fscanf(in, "%f", &number);
        i++;
    }
    aver = aver / quantity;
    *average = aver;
    return ZERO;
}

int main(const int argc, const char *const argv[])
{
    setbuf(stdout, NULL); // Чтобы в буфере ничего не держалось
    if (argc != TWO)
        return ARGS_ERROR;
    FILE *in = fopen(argv[ONE], "rt");
    if (!in)
        return FILE_ERROR;
    int ind_max = find_ind_max(in);
    if (ind_max < ZERO)
        return INCORRECT_INDEX;
    int ind_min = find_ind_min(in);
    if (ind_min < ZERO)
        return INCORRECT_INDEX;
    if (ind_min == ind_max)
        return EQ_INDEX;
    float average;
    int rc = find_average_between_indices(in, ind_min, ind_max, &average);
    if (rc)
        return rc;
    printf("%f", average);
    fclose(in);
    return 0;
}