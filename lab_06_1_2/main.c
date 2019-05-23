/* Написать программу, которая запрашивает у пользователя одну или две строки,
 * разбивает строку (или строки) на слова и выполняет обработку этих слов.
 * Разбиение строки на слова реализуется самостоятельно (использовать для
 * выделения слов функции scanf или strtok нельзя).
 * Длина строки не превышает 256 символов, длина слова - 16-ти символов.
 * Слова разделяются одним или несколькими пробелами и знаками пунктуации
 * (“,”, “;”, “:”, “-”, “.”, “!”, “?”).
 * Ввести одну строку. Составить массив из слов исходной строки (каждое слово должно
 * входить в массив только один раз). Упорядочить этот массив в лексикографическом
 * порядке. Слова из упорядоченного массива вывести на экран, разделив одним
 * пробелом
 */

#include <stdio.h>
#include <string.h>

int str_input(char* str)
{
    char symbol;
    scanf("%c", &symbol);
    int i = 0;
    while (symbol != '\n' && symbol && i < 255)
    {
        str[i] = symbol;
        i++;
        scanf("%c", &symbol);
    }
    if (i < 255)
    {
        str[i] = '\0';
        return 0;
    }
    else
        return 1;
}

int special_split(const char* str, char m[][16], const char* symbols)
{
    int i = 0, q = 0;
    int row = 0;
    int col = 0;
    while (str[i])
    {
        while (symbols[q])
        {
            if (symbols[q] == str[i])
            {
                if (col == 0)
                    break;
                m[row][col] = '\0';
                ++row;
                col = 0;
                break;
            }
                ++q;
        }
        if (symbols[q] == '\0')
        {
            m[row][col] = str[i];
            ++col;
        }
        q = 0;
        ++i;
    }
    m[row][col] = '\0';
    return ++row;
}

int del_row(const int row, char words[row][16], const int i)
{
    if (row <= 0 || i > row - 1)
        return -2;
    for (int j = i; j < row; j++)
    {
        for (int q = 0; q < 16; q++)
            words[j][q] = words[j + 1][q];
    }
    return 0;
}

int del_equal_strings(const int num, char words[num][16])
{
    if (num <= 0)
        return -1;
    int exactly = num, q, rc, j;
    for (int i = 0; i < exactly; i++)
    {
        j = i + 1;
        while (j < exactly)
        {
            q = 0;
            while (words[i][q] == words[j][q] && words[i][q] && words[j][q])
                q++;
            if (words[i][q] == '\0' && words[j][q] == '\0')
            {
                rc = del_row(exactly, words, j);
                if (rc)
                    return -2;
                exactly--;
            }
            else
                j++;
        }
    }
    return exactly;
}

int is_lex_bigger(const char* word1, const char* word2)
{
    int i = 0;
    while (word1[i] == word2[i] && word1[i] && word2[i])
        i++;
    if (word1[i] == '\0' && word2[i] == '\0')
        return 0;
    else if (word1[i] > word2[i] || (word2[i] == '\0' && word1[i] != '\0'))
        return 1;
    else
        return 0;
}

int change_places(const int curindex, const int nextindex, const int row, char words[row][16])
{
    if (row <= 0 || curindex > row || nextindex > row)
        return 4;
    char memory;
    int i = 0;
    while (words[curindex][i] || words[nextindex][i])
    {
        memory = words[curindex][i];
        words[curindex][i] = words[nextindex][i];
        words[nextindex][i] = memory;
        i++;
    }
    return 0;
}

int lexicographical_sort(const int row, const int col, char words[row][col])
{
    if (row <= 0 || col <= 0)
        return 3;
    int rc;
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < row - 1; j++)
        {
            if (is_lex_bigger(words[i], words[i + 1]))
            {
                rc = change_places(i, i + 1, row, words);
                if (rc)
                    return rc;
            }
        }
    }
    return 0;
}

int print_str(const int row, const int col, char string[row][col])
{
    if (row < 0 || col < 0)
        return 5;
    int j = 0;
    for (int i = 0; i < row; i++)
    {
        while (string[i][j])
        {
            printf("%c", string[i][j]);
            j++;
        }
        printf(" ");
        j = 0;
    }
    return 0;
}

int main(void)
{
    char string[256];
    int rc = str_input(string);
    if (rc)
        return rc;
    char split_items[9] = " ,.;:-!?", words[16][16];
    rc = special_split(string, words, split_items);
    if (rc == 0)
        return 2;
    int rows = rc;
    rc = del_equal_strings(rows, words);
    if (rc < 0)
        return rc;
    rc = lexicographical_sort(rc, 16, words);
    if (rc)
        return rc;
    rc = print_str(rows, 16, words);
    if (rc)
        return rc;
    return 0;
}