#include <stdio.h>
#include <stdlib.h>
#include "Headers/calc_u1.h"
#include "Headers/calc_u2.h"
#include "Headers/del.h"
#include "Headers/insert.h"
#include "Headers/print.h"
#include "Headers/invitation.h"

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
#define SATAN 666

int main(void)
{
    printf("Тесты для всего и всея (или не очень)\n");

    double *mas = calloc(5, sizeof(double));
    double u1 = 1;
    int positives = 0, negatives = 0;

    printf("Тесты для подпрограммы calc_u1\n");
    short check = calc_u1(5, &mas, &u1);
    printf("Тепличные значения. Переменная проверки: %d; Значение u1: %lf\n", check, u1);
    if (u1 - EPS < 0)
    {
        printf("Тест пройден\n");
        positives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = calc_u1(-1, &mas, &u1);
    printf("Негативный тест. Переменная проверки: %d; Количество членов массива: -1\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = calc_u1(5, NULL, &u1);
    printf("Негативный тест. Переменная проверки: %d; Указатель на массив: NULL\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = calc_u1(-1, &mas, NULL);
    printf("Негативный тест. Переменная проверки: %d; Указатель на u1: NULL\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    printf("Итого: %d/1 positive, %d/3 negatives\n", positives, negatives);
    if (positives == 1 && negatives == 3)
        printf("Тестирование функции проведено успешно.\n\n");
    else
        printf("А почему тесты не проходят?\n\n");

    positives = 0;
    negatives = 0;

    printf("Тесты для подпрограммы calc_u2\n");
    double u2 = 1;
    check = calc_u2(5, &mas, &u2);
    printf("Тепличные значения. Переменная проверки: %d; Значение u2: %lf\n", check, u2);
    if (u2 - EPS < 0)
    {
        printf("Тест пройден\n");
        positives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = calc_u2(-1, &mas, &u1);
    printf("Негативный тест. Переменная проверки: %d; Количество членов массива: -1\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = calc_u2(5, NULL, &u2);
    printf("Негативный тест. Переменная проверки: %d; Указатель на массив: NULL\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = calc_u1(-1, &mas, NULL);
    printf("Негативный тест. Переменная проверки: %d; Указатель на u1: NULL\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    printf("Итого: %d/1 positive, %d/3 negatives\n", positives, negatives);
    if (positives == 1 && negatives == 3)
        printf("Тестирование функции проведено успешно.\n\n");
    else
        printf("А почему тесты не проходят?\n\n");

    positives = 0;
    negatives = 0;

    printf("Тесты для подпрограммы del_from_mas_upmod_num\n");
    *mas = 1;
    *(mas + 1) = 2;
    *(mas + 2) = 3;
    *(mas + 3) = 4;
    *(mas + 4) = 5;
    int quantity = 5;
    check = del_from_mas_upmod_num(&mas, &quantity, 3.0);
    printf("Тепличные значения. Исходный массив: 1 2 3 4 5;\n"
        "Количество членов в массиве до: 5; Удаление по: 3;"
        " Количество членов в массиве после: %d;\n", quantity);
    if (quantity == 3)
    {
        printf("Тест пройден\n");
        positives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = del_from_mas_upmod_num(&mas, &quantity, -1);
    printf("Негативный тест. Переменная проверки: %d; Число удаления: -1\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = del_from_mas_upmod_num(NULL, &quantity, 3);
    printf("Негативный тест. Переменная проверки: %d; Указатель на массив: NULL\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = del_from_mas_upmod_num(&mas, NULL, 3);
    printf("Негативный тест. Переменная проверки: %d; Указатель на quantity: NULL\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    quantity = -2;
    check = del_from_mas_upmod_num(&mas, &quantity, 3);
    printf("Негативный тест. Переменная проверки: %d; Число в quantity: -2\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    quantity = 3;
    check = del_from_mas_upmod_num(&mas, &quantity, 0.1);
    printf("Негативный тест. Переменная проверки: %d; Удаление всех значений;\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    printf("Итого: %d/1 positive, %d/5 negatives\n", positives, negatives);
    if (positives == 1 && negatives == 5)
        printf("Тестирование функции проведено успешно.\n\n");
    else
        printf("А почему тесты не проходят?\n\n");

    mas = (double *)realloc(mas, sizeof(double) * 3);
    if (!(*mas))
    {
        printf("Oopsee-doopsee... Say 'hello' to you memory manager!");
        return SATAN;
    }
    *(mas + 1) = 2;
    *(mas + 2) = 3;

    positives = 0;
    negatives = 0;
    quantity = 3;
    printf("Тесты для подпрограммы insert_in_mas_by_pos_start_end\n");
    check = insert_in_mas_by_pos_start_end(&mas, &quantity, 1, 666.0);
    printf("Тепличные значения. Исходный массив: 1 2 3;\n"
        "Индекс вставки: 1; Добавление: 666;"
        " Массив после: %lf %lf %lf %lf %lf %lf;\n", *mas, *(mas + 1), *(mas + 2),
    *(mas + 3), *(mas + 4), *(mas + 5));
    if (*mas - 666 < EPS && *(mas + 1) - 666 < EPS && *(mas + 5) - 666 < EPS &&
        quantity == 6)
    {
        printf("Тест пройден\n");
        positives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = insert_in_mas_by_pos_start_end(NULL, &quantity, 1, 666.0);
    printf("Негативный тест. Переменная проверки: %d; Указатель на массив: NULL\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = insert_in_mas_by_pos_start_end(&mas, NULL, 1, 666.0);
    printf("Негативный тест. Переменная проверки: %d; Указатель на quantity: NULL\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = insert_in_mas_by_pos_start_end(NULL, &quantity, 6, 666.0);
    printf("Негативный тест. Переменная проверки: %d; Позиция из 5-и доступных: 6\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = insert_in_mas_by_pos_start_end(&mas, &quantity, -1, 666.0);
    printf("Негативный тест. Переменная проверки: %d; Позиция из 5-и доступных: -1\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    quantity = -2;
    check = insert_in_mas_by_pos_start_end(&mas, &quantity, 6, 666.0);
    printf("Негативный тест. Переменная проверки: %d; Число в quantity: -2\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    printf("Итого: %d/1 positive, %d/5 negatives\n", positives, negatives);
    if (positives == 1 && negatives == 5)
        printf("Тестирование функции проведено успешно.\n\n");
    else
        printf("А почему тесты не проходят?\n\n");

    negatives = 0;
    printf("Тестирование подпрограммы invitation_len_mas_pos\n");
    double *scoobey_doo_where_are_you;

    check = invitation_len_mas_pos(666, &scoobey_doo_where_are_you, NULL);
    printf("Негативный тест. Переменная проверки: %d; Указатель на позицию: NULL\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    printf("Итого: 0/0 positive, %d/1 negatives\n", negatives);
    if (negatives == 1)
        printf("Тестирование функции проведено успешно.\n\n");
    else
        printf("А почему тесты не проходят?\n\n");

    negatives = 0;
    positives = 0;

    printf("Тесты для подпрограммы print_double_array\n");
    quantity = 6;
    check = print_double_array(mas, quantity);
    printf("Тепличные значения. Переменная проверки: %d;\n", check);
    if (!check)
    {
        printf("Тест пройден\n");
        positives++;
    }
    else
        printf("\nТест не пройден :(\n");

    check = print_double_array(&mas, -1);
    printf("Негативный тест. Переменная проверки: %d; Количество членов массива: -1\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    check = print_double_array(NULL, quantity);
    printf("Негативный тест. Переменная проверки: %d; Указатель на массив: NULL\n", check);
    if (check)
    {
        printf("Тест пройден\n");
        negatives++;
    }
    else
        printf("Тест не пройден :(\n");

    printf("Итого: %d/1 positive, %d/2 negatives\n", positives, negatives);
    if (positives == 1 && negatives == 2)
        printf("Тестирование функции проведено успешно.\n\n");
    else
        printf("А почему тесты не проходят?\n\n");

    free(mas);
    return 0;
}
