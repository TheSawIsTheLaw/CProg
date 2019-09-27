#include <stdio.h>
#include <stdlib.h>
#include "../Headers/calc_u1.h"
#include "../Headers/calc_u2.h"
#include "../Headers/del.h"
#include "../Headers/insert.h"
#include "../Headers/print.h"

/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0

/**
 * \def EPS
 * \brief Переменная для сравнения чисел double
 */
#define EPS 0.0000000001

/**
 * \def TEST_ERROR
 * \brief Ошибка при тестировании
 */
#define TEST_ERROR 666

int main(void)
{
    short check, positives = 0, negatives = 0;

    double *mas = (double*)calloc(5, sizeof(double));

    double u1 = 0, u2 = 0;

    for (short i = 0; i < 5; i++)
        *(mas + i) = 1;

    // calc_u1

    check = calc_u1(5, mas, &u1);

    if (!check && u1 == 1)
        positives++;

    *mas = 2;

    if (!check && u1 - 1.018181818 < EPS)
        positives++;

    check = calc_u1(0, mas, &u1);

    if (check)
        negatives++;

    check = calc_u1(-1, mas, &u1);

    if (check)
        negatives++;

    check = calc_u1(5, NULL, &u1);

    if (check)
        negatives++;

    check = calc_u1(5, mas, NULL);

    if (check)
        negatives++;

    // calc_u2

    *mas = 1;

    check = calc_u1(5, mas, &u2);

    if (!check && u2 == 1)
        positives++;

    *mas = 2;

    if (!check && u2 - 1.2 < EPS)
        positives++;

    check = calc_u2(0, mas, &u2);

    if (check)
        negatives++;

    check = calc_u2(-1, mas, &u2);

    if (check)
        negatives++;

    check = calc_u2(5, NULL, &u2);

    if (check)
        negatives++;

    check = calc_u2(5, mas, NULL);

    if (check)
        negatives++;

    if (negatives != 8 || positives != 4)
        return TEST_ERROR;

    int quantity = 5;

/*    // del_from_mas_upmod_num

    negatives = 0;
    positives = 0;

    check = del_from_mas_upmod_num(NULL, &quantity, 2);

    if (check)
        negatives++;

    check = del_from_mas_upmod_num(mas, NULL, 2);

    if (check)
        negatives++;

    quantity = 0;
    check = del_from_mas_upmod_num(mas, &quantity, 2);

    if (check)
        negatives++;

    quantity = -1;
    check = del_from_mas_upmod_num(mas, &quantity, 2);

    if (check)
        negatives++;

    quantity = 5;
    check = del_from_mas_upmod_num(mas, &quantity, 0);

    if (check)
        negatives++;

    check = del_from_mas_upmod_num(mas, &quantity, -666);

    if (check)
        negatives++;

    mas = (double*)realloc(mas, sizeof(double) * 5);
    for (short i = 1; i < 5; i++)
        *(mas + i) = -1.5;

    *mas = 1;

    *check = del_from_mas_upmod_num(mas, &quantity, 2);
    
    printf("check = %d ", check);

    if (!check && quantity == 5)
        positives++;

    mas = (double*)realloc(mas, sizeof(double) * 5);
    for (short i = 1; i < 5; i++)
        *(mas + i) = 2.5;

    *mas = 1;

    check = del_from_mas_upmod_num(mas, &quantity, 2);
    
    printf("check = %d ", check);

    if (!check && quantity == 1 && *mas == 1)
        positives++;

    if (positives != 2 || negatives != 6)
        return TEST_ERROR;
    */
    // insert_in_mas_by_pos_start_end

    negatives = 0;
    positives = 0;

    mas = (double*)realloc(mas, sizeof(double) * 5);
    for (short i = 1; i < 5; i++)
        *(mas + i) = 2.5;
    quantity = 5;

    check = insert_in_mas_by_pos_start_end(NULL, &quantity, 1, 6.66);

    if (check)
        negatives++;

    check = insert_in_mas_by_pos_start_end(mas, NULL, 1, 6.66);

    if (check)
        negatives++;

    check = insert_in_mas_by_pos_start_end(mas, &quantity, 8, 6.66);

    if (check)
        negatives++;

    check = insert_in_mas_by_pos_start_end(mas, &quantity, -2, 6.66);

    if (check)
        negatives++;

    check = insert_in_mas_by_pos_start_end(mas, &quantity, 0, 6.66);

    if (!check && *mas == 6.66 && *(mas + 1) == 6.66 && *(mas + 7) == 6.66)
        positives++;

    mas = (double*)realloc(mas, sizeof(double) * 5);
    for (short i = 1; i < 5; i++)
        *(mas + i) = 2.5;
    quantity = 5;

    check = insert_in_mas_by_pos_start_end(mas, &quantity, 2, 6.66);

    if (!check && *mas == 6.66 && *(mas + 1) == 6.66 && *(mas + 7) == 6.66)
        positives++;

    if (positives != 2 || negatives != 4)
        return TEST_ERROR;

    // print_double_array

    negatives = 0;

    check = print_double_array(mas, 0);

    if (check)
        negatives++;

    check = print_double_array(mas, -1);

    if (check)
        negatives++;

    check = print_double_array(NULL, quantity);

    if (check)
        negatives++;

    if (negatives != 3)
        return TEST_ERROR;

    return SUCCESS;
}
