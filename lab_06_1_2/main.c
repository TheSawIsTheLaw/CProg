/**
 * \file main.c
 * \brief Написать программу, которая запрашивает у пользователя одну или
 * две строки, разбивает строку (или строки) на слова и выполняет обработку
 * этих слов. Разбиение строки на слова реализуется самостоятельно
 * (использовать для выделения слов функции scanf или strtok нельзя).
 * Длина строки не превышает 256 символов, длина слова - 16-ти символов.
 * Слова разделяются одним или несколькими пробелами и знаками пунктуации
 * (“,”, “;”, “:”, “-”, “.”, “!”, “?”).
 * Ввести одну строку. Составить массив из слов исходной строки (каждое слово
 * должно входить в массив только один раз). Упорядочить этот массив в
 * лексикографическом порядке. Слова из упорядоченного массива вывести на
 * экран, разделив одним пробелом.
 * Коды ошибок:
 *
 * -2 - в функцию del_row были переданы некорректные данные;
 *
 * -1 - в функцию del_equal_strings были переданы некорректные данные;
 *
 * 1 - не все введённые значения были присвоены переменным;
 *
 * 3 - в функцию lexicographical_sort были переданы некорректные данные;
 *
 * 4 - в функцию change_places были переданы некорректные данные;
 *
 * 5 - в функцию print_str были переданы некорректные данные;
 *
 * 6 - в функцию print_str была передан пустой массив;
 */
#include <stdio.h>
#include <string.h>

/**
 * \def NTWO
 * \brief Код ошибки или просто число
 */
#define NTWO -2
/**
 * \def NONE
 * \brief Код ошибки или просто число
 */
#define NONE -1
/**
 * \def IZ
 * \brief Терминальный нуль
 */
#define IZ '\0'
/**
 * \def ZERO
 * \brief Просто число или код "всё хорошо"
 */
#define ZERO 0
/**
 * \def ONE
 * \brief Код ошибки или просто число
 */
#define ONE 1
/**
 * \def TWO
 * \brief Просто число
 */
#define TWO 2
/**
 * \def THREE
 * \brief Код ошибки или просто число
 */
#define THREE 3
/**
 * \def FOUR
 * \brief Код ошибки или просто число
 */
#define FOUR 4
/**
 * \def FIVE
 * \brief Код ошибки или просто число
 */
#define FIVE 5
/**
 * \def SIX
 * \brief Код ошибки или просто число
 */
#define SIX 6
/**
 * \def NINE
 * \brief Просто число
 */
#define NINE 9
/**
 * \def SIXTEEN
 * \brief Максимальная длина слова
 */
#define SIXTEEN 16
/**
 * \def MAX_LEN
 * \brief Максимальная длина строки
 */
#define MAX_LEN 256

/**
 * \fn int str_input(char *str)
 * \brief Принимает строку от пользователя
 *
 * \param [out] str То, куда записывается строка
 * \return Код ошибки или успешного завершения
 */
int str_input(char *str)
{
    char symbol;
    int rc;
    rc = scanf("%c", &symbol);
    if (rc != ONE)
        return ONE;
    int i = ZERO;
    while (symbol != '\n' && symbol && i < MAX_LEN)
    {
        str[i] = symbol;
        i++;
        rc = scanf("%c", &symbol);
        if (rc != ONE)
            return ONE;
    }
    if (i < MAX_LEN && i > ZERO)
    {
        str[i] = IZ;
        return ZERO;
    }
    else
        return ONE;
}

/**
 * \fn int special_split(const char *str, char m[][SIXTEEN],
 * const char *symbols)
 * \brief Специальный сплит по мноежству символов
 *
 * \param [out] str Обрабатываемая строка
 * \param [out] m Массив, куда записываются все слова
 * \param [out] symbols Символы, по которым строка разделяется
 * \return Количество слов в полученном массиве
 */
int special_split(const char *str, char m[][SIXTEEN], const char *symbols)
{
    int i = ZERO, q = ZERO, row = ZERO, col = ZERO;
    while (str[i])
    {
        while (symbols[q])
        {
            if (symbols[q] == str[i])
            {
                if (col == ZERO)
                    break;
                m[row][col] = IZ;
                row++;
                col = ZERO;
                break;
            }
            q++;
        }
        if (symbols[q] == IZ)
        {
            m[row][col] = str[i];
            col++;
        }
        q = ZERO;
        i++;
    }
    m[row][col] = IZ;
    row++;
    return row;
}

/**
 * \fn int del_row(const int row, char words[row][SIXTEEN], const int i)
 * \brief Удаляет указанную строку из матрицы слов
 *
 * \param [out] row Количество строк в матрице
 * \param [out] words То, откуда удаляется строка
 * \param [out] i Индекс удаляемой строки
 * \return Код ошибки или успешного завершения
 */
int del_row(const int row, char words[row][SIXTEEN], const int i)
{
    if (row <= ZERO || i > row - ONE)
        return NTWO;
    for (int j = i; j < row - ONE; j++)
    {
        for (int q = ZERO; q < SIXTEEN; q++)
            words[j][q] = words[j + ONE][q];
    }
    return ZERO;
}

/**
 * \fn int del_equal_strings(const int num, char words[num][SIXTEEN])
 * \brief Удаляет эквивалентные строки из файла
 *
 * \param [out] num Количество строк в матрице
 * \param [out] words То, откуда удаляется строка
 * \return Код ошибки или итоговое количество строк
 */
int del_equal_strings(const int num, char words[num][SIXTEEN])
{
    if (num <= ZERO)
        return NONE;
    int exactly = num, q, rc, j;
    for (int i = ZERO; i < exactly - ONE; i++)
    {
        j = i + ONE;
        while (j < exactly)
        {
            q = ZERO;
            while (words[i][q] == words[j][q] &&
                words[i][q] && words[j][q])
                q++;
            if (words[i][q] == IZ && words[j][q] == IZ)
            {
                rc = del_row(exactly, words, j);
                if (rc)
                    return rc;
                exactly--;
            }
            else
                j++;
        }
    }
    return exactly;
}

/**
 * \fn int is_lex_bigger(const char *word1, const char *word2)
 * \brief Сравнивает строки по лексикографическому признаку
 *
 * \param [out] word1 Первая строка
 * \param [out] word2 Вторая строка
 * \return 0 - второе больше первого, 1 - наоборот
 */
int is_lex_bigger(const char *word1, const char *word2)
{
    int i = ZERO;
    while (word1[i] == word2[i] && word1[i] && word2[i])
        i++;
    if (word1[i] == IZ && word2[i] == IZ)
        return ZERO;
    else if (word1[i] > word2[i] || (word2[i] == IZ &&
        word1[i] != IZ))
        return ONE;
    else
        return ZERO;
}

/**
 * \fn int change_places(const int curindex, const int nextindex,
 * const int row, char words[row][SIXTEEN])
 * \brief Меняет слова в массиве слов местами
 *
 * \param [out] curindex Индекс первого слова
 * \param [out] nextindex Индекс второго слова
 * \param [out] row Количество слов в массиве
 * \param [out] words Массив слов
 * \return Код ошибки или успешного завершения
 */
int change_places(const int curindex, const int nextindex,
    const int row, char words[row][SIXTEEN])
{
    if (row <= ZERO || curindex > row || nextindex > row)
        return FOUR;
    char memory;
    int i = ZERO;
    while (words[curindex][i] || words[nextindex][i])
    {
        memory = words[curindex][i];
        words[curindex][i] = words[nextindex][i];
        words[nextindex][i] = memory;
        i++;
    }
    return ZERO;
}

/**
 * \fn int lexicographical_sort(const int row, const int col,
 * char words[row][col])
 * \brief Сортирует лексикографически массив слов
 *
 * \param [out] row Количество слов в массиве
 * \param [out] col Максимальная длина слова
 * \param [out] words Массив слов
 * \return Код ошибки или успешного завершения
 */
int lexicographical_sort(const int row, const int col,
    char words[row][col])
{
    if (row <= ZERO || col <= ZERO)
        return THREE;
    int rc;
    for (int i = ZERO; i < row - ONE; i++)
    {
        for (int j = ZERO; j < row - ONE; j++)
        {
            if (is_lex_bigger(words[j], words[j + ONE]))
            {
                rc = change_places(j, j + ONE, row, words);
                if (rc)
                    return rc;
            }
        }
    }
    return ZERO;
}

/**
 * \fn int print_str(const int row, const int col, char string[row][col])
 * \brief Выводит массив слов на экран
 *
 * \param [out] row Количество слов в массиве
 * \param [out] col Максимальная длина слова
 * \param [out] words Массив слов
 * \return Код ошибки или успешного завершения
 */
int print_str(const int row, const int col, char string[row][col])
{
    if (row < ZERO || col < ZERO)
        return FIVE;
    int j = ZERO, k = ZERO;
    for (int i = ZERO; i < row; i++)
    {
        while (string[i][j])
        {
            if (k == ZERO)
                printf("Result:");
            printf("%c", string[i][j]);
            j++;
            k++;
        }
        if (j != ZERO)
            printf(" ");
        j = ZERO;
    }
    if (k == ZERO)
        return SIX;
    return ZERO;
}

int main(void)
{
    char string[MAX_LEN] = { ZERO };
    int rc = str_input(string);
    if (rc)
        return rc;
    char split_items[NINE] = " ,.;:-!?",
        words[SIXTEEN][SIXTEEN] = { ZERO };
    rc = special_split(string, words, split_items);
    if (rc == ZERO)
        return TWO;
    int rows = rc;
    rows = del_equal_strings(rows, words);
    if (rows < ZERO)
        return rows;
    rc = lexicographical_sort(rows, SIXTEEN, words);
    if (rc)
        return rc;
    rc = print_str(rows, SIXTEEN, words);
    if (rc)
        return rc;
    return 0;
}
