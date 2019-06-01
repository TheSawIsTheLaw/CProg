/**
 * \file main.c
 * \brief Написать программу, которая обрабатывает двоичный
 * файл, содержащий целые числа.
 * Программа должна уметь:
 * − создавать файл и заполнять его случайными числами;
 * − выводить числа из файла на экран;
 * − упорядочивать числа в файле.
 *
 * Выбран тип integer, алгоритм сортировки - quiсksort,
 * упорядочивание идёт по неуменьшению.
 *
 * s - сортировка;
 *
 * p - вывод чисел из файла;
 *
 * m - создание файла;
 *
 * Коды ошибок:
 *
 * -666 - В функцию были переданы
 * некорректные аргументы;
 *
 * -667 - В функцию get_number_by_pos переданы
 * некорректные аргументы;
 * 
 * -668 - В функцию put_number_by_pos переданы
 * некорректные аргументы;
 * 
 * -669 - В функцию from_mas_to_bin_file переданы
 * некорректные аргументы;
 * 
 * -2 - Файла не существует или он недоступен;
 *
 * -1 - Файл пуст.
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/**
 * \def ARGS_ERROR
 * \brief В функцию переданы некорректные аргументы
 */
#define ARGS_ERROR -666
/**
 * \def ARGS_ERROR1
 * \brief В функцию get_number_by_pos переданы
 * некорректные аргументы
 */
#define ARGS_ERROR1 -667
/**
 * \def ARGS_ERROR2
 * \brief В функцию put_number_by_pos переданы
 * некорректные аргументы
 */
#define ARGS_ERROR2 -668
/**
 * \def ARGS_ERROR3
 * \brief В функцию from_mas_to_bin_file переданы
 * некорректные аргументы
 */
#define ARGS_ERROR3 -669
/**
 * \def FILE_ERROR
 * \brief Файла не существует или он недоступен
 */
#define FILE_ERROR -2
/**
 * \def FILE_IS_EMPTY
 * \brief Файл пуст
 */
#define FILE_IS_EMPTY -1
/**
 * \def ZERO
 * \brief Просто число или "всё прошло успешно"
 */
#define ZERO 0
/**
 * \def ZERO
 * \brief Просто число
 */
#define ONE 1
/**
 * \def TWO
 * \brief Просто число
 */
#define TWO 2
/**
 * \def THREE
 * \brief Просто число
 */
#define THREE 3
/**
 * \def TEN
 * \brief Просто число
 */
#define TEN 10
/**
 * \def NHUND
 * \brief Число для рандомайзера
 */
#define NHUND -100
/**
 * \def TWOHUND
 * \brief Число для рандомайзера
 */
#define TWOHUND 200

/**
 * \fn int get_number_by_pos(FILE *const in, const int pos,
 * int *const number)
 * \brief По заданной позиции, позволяет прочитать число в
 * указанной позиции
 *
 * \param [out] in Файловая переменная
 * \param [out] pos Позиция
 * \param [out] number Адрес, куда направится значение
 * \return Код ошибки или успешного совершения операции
 */
int get_number_by_pos(FILE *const in, const int pos,
    int *const number)
{
    if (!in)
        return FILE_ERROR;
    if (pos < ZERO)
        return ARGS_ERROR1;
    fseek(in, sizeof(int) * pos, SEEK_SET);
    fread(&(*number), sizeof(int), ONE, in);
    return ZERO;
}

/**
 * \fn int put_number_by_pos(FILE *const in, const int pos,
 * const int number)
 * \brief Позволяет записать число в
 * указанную позицию
 *
 * \param [out] in Файловая переменная
 * \param [out] pos Позиция
 * \param [out] number Число, которое будет запсиано
 * \return Код ошибки или успешного совершения операции
 */
int put_number_by_pos(FILE *const in, const int pos,
    const int number)
{
    if (!in)
        return FILE_ERROR;
    if (pos < ZERO)
        return ARGS_ERROR2;
    fseek(in, sizeof(int) * pos, SEEK_SET);
    fwrite(&number, sizeof(int), ONE, in);
    return ZERO;
}

/**
 * \fn int binary_ints_to_mas(FILE *const in, const int num,
 * int mas[])
 * \brief Записывает все числа из бинарного файла в массив
 *
 * \param [out] in Файловая переменная
 * \param [out] mas Заполняемый массив
 * \return Код ошибки или успешного совершения операции
 */
int binary_ints_to_mas(FILE *const in, const int num, int mas[])
{
    if (!in)
        return FILE_ERROR;
    int pos = ZERO, rc;
    for (int i = ZERO; i < num; i++)
    {
        rc = get_number_by_pos(in, i, &mas[pos]);
        if (rc)
            return rc;
        pos++;
    }
    return ZERO;
}

/**
 * \fn int from_mas_to_bin_file(FILE *const in, const int num,
 *  const int mas[])
 * \brief Записывает все числа из массива в бинарный файл
 *
 * \param [out] in Файловая переменная
 * \param [out] num Количество ячеек в массиве
 * \param [out] mas Заполняемый массив
 * \return Код ошибки или успешного совершения операции
 */
int from_mas_to_bin_file(FILE *const in, const int num,
    const int mas[])
{
    if (!in)
        return FILE_ERROR;
    if (num < ZERO)
        return ARGS_ERROR3;
    int rc;
    for (int i = ZERO; i < num; i++)
    {
        rc = put_number_by_pos(in, i, mas[i]);
        if (rc)
            return rc;
    }
    return ZERO;
}

/**
 * \fn void quicksort(int mas[], int first, int last)
 * \brief Быстрая сортировка массива
 *
 * \param [out] mas Обрабатываемый массив
 * \param [out] first Начальный индекс
 * \param [out] last Конечный индекс сортировки
 * \return Void
 */
void quicksort(int mas[], int first, int last)
{
    if (first < last)
    {
        int left = first, right = last,
            middle = mas[(left + right) / TWO];
        while (left <= right)
        {
            while (mas[left] < middle)
                left++;
            while (mas[right] > middle)
                right--;
            if (left <= right)
            {
                int tmp = mas[left];
                mas[left] = mas[right];
                mas[right] = tmp;
                left++;
                right--;
            }
        }
        quicksort(mas, first, right);
        quicksort(mas, left, last);
    }
}

/**
 * \fn int find_size_of_bin(FILE *const in)
 * \brief Определяет количество чисел в бинарном файле
 *
 * \param [out] in Файловая переменная
 * \return Код ошибки или успешного совершения операции
 */
int find_size_of_bin(FILE *const in)
{
    if (!in)
        return FILE_ERROR;
    fseek(in, ZERO, SEEK_SET);
    int size = ZERO, num, n = fread(&num,
        sizeof(int), ONE, in);
    while (n)
    {
        size++;
        n = fread(&num, sizeof(int), ONE, in);
    }
    return size;
}

/**
 * \fn int print_bin(FILE *const in)
 * \brief Выводит на экран содержимое бинарного файла
 *
 * \param [out] in Файловая переменная
 * \return Код ошибки или успешного совершения операции
 */
int print_bin(FILE *const in)
{
    if (!in)
        return FILE_ERROR;
    fseek(in, ZERO, SEEK_SET);
    int i = ZERO, num, n = fread(&num, sizeof(int),
        ONE, in);
    while (n)
    {
        i++;
        printf("%d ", num);
        n = fread(&num, sizeof(int), ONE, in);
    }
    return i;
}

/**
 * \fn int full_bin(FILE *const in, const int num)
 * \brief Заполняет бинарный файл случайными числами
 *
 * \param [out] in Файловая переменная
 * \param [out] num Количество чисел
 * \return Код ошибки или успешного совершения операции
 */
int full_bin(FILE *const in, const int num)
{
    if (!in)
        return FILE_ERROR;
    int number;
    srand(time(NULL));
    for (int i = ZERO; i < num; i++)
    {
        number = NHUND + rand() % TWOHUND;
        put_number_by_pos(in, i, number);
    }
    return ZERO;
}

int main(const int argc, const char *const argv[])
{
    setbuf(stdout, NULL);
    if (argc != THREE)
        return ARGS_ERROR;
    if (*argv[ONE] == 's')
    {
        FILE *in = fopen(argv[TWO], "rb");
        if (!in)
            return FILE_ERROR;
        int number = find_size_of_bin(in);
        if (number == ZERO)
            return FILE_IS_EMPTY;
        if (number < ZERO)
            return number;
        int mas[number];
        memset(mas, ZERO, number * sizeof(int));
        int rc = binary_ints_to_mas(in, number, mas);
        if (rc < ZERO)
            return rc;
        fclose(in);
        quicksort(mas, ZERO, number - ONE);
        in = fopen(argv[TWO], "wb");
        from_mas_to_bin_file(in, number, mas);
        fclose(in);
    }
    else if (*argv[ONE] == 'p')
    {
        FILE *in = fopen(argv[TWO], "rb");
        if (!in)
            return FILE_ERROR;
        int rc = print_bin(in);
        if (rc < ZERO)
            return rc;
        if (rc == ZERO)
            return FILE_IS_EMPTY;
    }
    else if (*argv[ONE] == 'm')
    {
        FILE *in = fopen(argv[TWO], "wb");
        if (!in)
            return FILE_ERROR;
        int rc = full_bin(in, TEN);
        if (rc)
            return rc;
        fclose(in);
    }
    return 0;
}