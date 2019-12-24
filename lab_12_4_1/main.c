/*
 * Лабораторная работа номер 12, Якуба Дмитрий, ИУ7-33Б
 * Вариант 4.
 *
 * В виде списка представлены множители и степени разложения
 * целого положительного числа 𝑛 на простые множители.
 *
 * Реализовать подпрограмму умножения двух таких чисел.
 *
 * Реализовать подпрограмму возведения числа в квадрат.
 *
 * Реализовать подпрограмму деления без остатка.
 *
 * При старте программы пользователь вводит одно из четырёх слов: out, mul,
 * sqr, div. При вводе out далее идёт одно целое число, которое нужно вывести
 * на экран в виде списка. В остальных случаях за словом вводится одно или два
 * числа, над которыми требуется выполнить операцию, реализованную в виде
 * соответствующей подпрограммы. Если в результате получается нуль, считать
 * ситуацию ошибочной.
 *
 * Выводить число, сохранённое в виде списка, на экран в одну строку через пробел
 * по два числа, от старшего множителя и его степени к младшему. После вывода
 * в той же строке печатать единицу (думать, почему так, я не буду, так как работаю
 * я просто по ТЗ. Я планктон. Будущий офисный планктон.).
 *
 */

#include "headers/main.h"

#define OUT_FILE_ERROR 001
#define KEY_ERROR 002
#define UNKNOWN_KEY 003

int main(void)
{
    if (!F_OUT)
        return OUT_FILE_ERROR;

    char key[7];

    int check = fscanf(F_IN, "%s", key);

    if (check != 1)
        return KEY_ERROR;

    if (!strcmp(key, "out"))
    {
        //check = out();
        if (check)
            return check;
    }
    else if (!strcmp(key, "div"))
    {
        check = my_div();
        if (check)
            return check;
    }
    else if (!strcmp(key, "mul"))
    {
        check = mul();
        if (check)
            return check;
    }
    else if (!strcmp(key, "sqr"))
    {
        check = sqr();
        if (check)
            return check;
    }
    else
        return UNKNOWN_KEY;



    return 0;
}
