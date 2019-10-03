/**
 * \file main.с
 * \brief Лабораборная работа номер 8.
 * Вариант 4.
 * Задание: Принять с клавиатуры положительное целое 𝑛 и последовательность
 * 𝑛 действительных чисел, которые следует записать в динамический массив 𝐴.
 * Вычислить в соответствии с вариантом число 𝜇1 = 𝜇1(𝐴).
 * Получить массив 𝐴1, удалив в соответствии с вариантом из динамического
 * массива 𝐴 набор элементов по признаку. Обратите внимание: даже если на
 * этом шаге несколько раз используется уже вычисленное 𝜇1, то оно не
 * вычисляется заново. Если массив 𝐴1 сформировать невозможно, или он
 * формируется пустым, считать ситуацию исключительной.
 * Вычислить в соответствии с вариантом число 𝜇2 = 𝜇2(𝐴1).
 * Получив с клавиатуры номер позиции 𝑝, сформировать массив 𝐴2, вставив
 * с сохранением порядка сначала на позицию 𝑝 массива 𝐴1, а затем добавив
 * в начало и в конец число 𝜇2. Обратите внимание: даже если на этом шаге
 * используется несколько раз уже вычисленное 𝜇2, то оно не вычисляется заново.
 * Если на момент вставки на позицию 𝑝 в массиве меньше, чем 𝑝 + 1 элементов,
 * считать ситуацию исключительной.
 * Распечатать на экран массив 𝐴2.
 *
 * Для варианта 4 число 𝜇1 вычисляется по формуле среднего арифметического
 * взвешенного (сюда мне это не перенести, хоть убейте) и удаляются все
 * элементы, модуль которых больше 𝜇1.
 * Число 𝜇2 = sum(len(x) - 1, i = 0)(x(i)/len(x))
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Headers/invitation.h"
#include "Headers/calc_u1.h"
#include "Headers/calc_u2.h"
#include "Headers/del.h"
#include "Headers/insert.h"
#include "Headers/print.h"

/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0
/**
 * \def QUANTITY_ERROR
 * \brief Код ошибки в подпрограмме invitation_len_mas_pos
 */
#define QUANTITY_ERROR 1
/**
 * \def EDM_REALLOC_ERROR
 * \brief Код ошибки в подпрограмме expand_dyn_mas
 */
#define EDM_REALLOC_ERROR 2
/**
 * \def READ_ARRAY_ERROR
 * \brief Код ошибки в подпрограмме expand_dyn_mas
 */
#define READ_ARRAY_ERROR 3
/**
 * \def POS_ERROR
 * \brief Код ошибки в подпрограмме invitation_len_mas_pos
 */
#define POS_ERROR 4
/**
 * \def EDM_DATA_ERROR
 * \brief Код ошибки в подпрограмме invitation_len_mas_pos
 */
#define EDM_DATA_ERROR 5
/**
 * \def C_U1_DATA_ERROR
 * \brief Код ошибки в подпрограмме calc_u1
 */
#define C_U1_DATA_ERROR 6
/**
 * \def C_U2_DATA_ERROR
 * \brief Код ошибки в подпрограмме calc_u2
 */
#define C_U2_DATA_ERROR 7
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
 * \def PDA_DATA_ERROR
 * \brief Код ошибки в подпрограмме print_double_array
 */
#define PDA_DATA_ERROR 13

/**
 * \fn int main()
 * \brief Точка входа в программу
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения (нуль)
 */
int main(void)
{
    /* Количество членов в массиве, указатель на массив и позиция,
    с которой предстоит работать далее */
    short check;

    int quantity, pos;

    double *mas;

    // Принимаем значения
    check = invitation_len_mas_pos(&quantity, &mas, &pos);

    if (check)
    {
        free(mas);
        return check;
    }

    double u1;
    check = calc_u1(quantity, mas, &u1);
    if (check)
    {
        free(mas);
        return check;
    }

    check = del_from_mas_upmod_num(&mas, &quantity, u1);

    double u2;
    check = calc_u2(quantity, mas, &u2);
    if (check)
    {
        free(mas);
        return check;
    }

    check = insert_in_mas_by_pos_start_end(&mas, &quantity, pos, u2);
    if (check)
    {
        free(mas);
        return check;
    }

    check = print_double_array(mas, quantity);

    if (check)
    {
        free(mas);
        return check;
    }

    free(mas);

    return SUCCESS;
}
