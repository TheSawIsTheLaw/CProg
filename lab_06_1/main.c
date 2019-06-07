/**
 * \file main.c
 * \brief Реализация различных функций библиотеки string.h
 */

#include <stdio.h>
#include <string.h>

/**
 * \def ZERO
 * \brief Просто число или код "всё хорошо"
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
 * \def FOUR
 * \brief Просто число
 */
#define FOUR 4
/**
 * \def SIX
 * \brief Просто число
 */
#define SIX 6
/**
 * \def SEVEN
 * \brief Просто число
 */
#define SEVEN 7
/**
 * \def EIGHT
 * \brief Просто число
 */
#define EIGHT 8
/**
 * \def TEN
 * \brief Просто число
 */
#define TEN 10
/**
 * \def ELEVEN
 * \brief Просто число
 */
#define ELEVEN 11
/**
 * \def TESTS
 * \brief Количество тестов
 */
#define TESTS 14
/**
 * \def SEVENTEEN
 * \brief Просто число
 */
#define SEVENTEEN 17
/**
 * \def NINETEEN
 * \brief Просто число
 */
#define NINETEEN 19
/**
 * \def TWENTYTWO
 * \brief Просто число
 */
#define TWENTYTWO 22
/**
 * \def TWENTYEIGHT
 * \brief Просто число
 */
#define TWENTYEIGHT 28
/**
 * \def THIRTYEIGHT
 * \brief Просто число
 */
#define THIRTYEIGHT 38

/**
 * \fn char *my_strpbrk(const char *str1, const char *str2)
 * \brief Функция возвращает указатель на первый символ в строке, на которую
 * указывает str1, совпадающий с каким-нибудь из символов строки, на которую
 * указывает str2. Нулевые символы в конце строк в рассмотрение не включаются.
 */
char *my_strpbrk(const char *str1, const char *str2)
{
    int i = ZERO, j = ZERO;
    while (str1[i])
    {
        while (str2[j])
        {
            if (str2[j] == str1[i])
                return (char*)str1 + i;
            j++;
        }
        j = ZERO;
        i++;
    }
    return NULL;
}

/**
 * \fn size_t my_strspn(const char *str1, const char *str2)
 * \brief Функция возвращает количество символов в начале строки с указателем
 * str1, в число которых входят только символы, имеющиеся в строке с указателем
 * str2. Другими словами, для строки str1 функция strspn() возвращает значение
 * индекса первого символа из числа символов, не входящих в строку str2.
 */
size_t my_strspn(const char *str1, const char *str2)
{
    int i = ZERO, j = ZERO, num = ZERO;
    while (str1[i])
    {
        while (str2[j])
        {
            if (str2[j] == str1[i])
            {
                num++;
                break;
            }
            j++;
        }
        if (str2[j])
        {
            j = ZERO;
            i++;
        }
        else
            return num;
    }
    return num;
}

/**
 * \fn size_t my_strcspn(const char *str1, const char *str2)
 * \brief Функция strcspn выполняет поиск первого вхождения в строку string1
 * любого из символов строки string2, и возвращает количество символов до
 * найденного первого вхождения.
 */
size_t my_strcspn(const char *str1, const char *str2)
{
    int i = ZERO, j = ZERO, num = ZERO;
    while (str1[i])
    {
        while (str2[j])
        {
            if (str2[j] == str1[i])
            {
                return num;
            }
            j++;
        }
        j = ZERO;
        i++;
        num++;
    }
    return num;
}

/**
 * \fn char *my_strchr(const char *string, int symbol)
 * \brief Функция strchr выполняет поиск первого вхождения символа symbol в
 * строку string. Возвращает указатель на первое вхождение символа в
 * строке. Завершающий нулевой символ считается частью Си-строки.
 * Таким образом, он также может быть найден для получения указателя
 * на конец строки.
 */
char *my_strchr(const char *string, int symbol)
{
    int i = ZERO;
    while (string[i])
    {
        if (string[i] == (char)symbol)
            return (char*)string + i;
        i++;
    }
    if (string[i] == (char)symbol)
        return (char*)string + i;
    return NULL;
}

/**
 * \fn char *my_strrchr(const char *string, int symbol)
 * \brief Функция ищет последнее вхождение символа symbol в строку string.
 * Возвращает указатель на последнее вхождение символа в строке string.
 * Завершающий нулевой символ считается частью строки. Таким образом, он
 * также может быть найден для получения указателя на конец строки.
 */
char *my_strrchr(const char *string, int symbol)
{
    int i = ZERO;
    while (string[i])
        i++;
    while (i + ONE)
    {
        if (string[i] == (char)symbol)
        {
            return (char*)string + i;
        }
        i--;
    }
    return NULL;
}

int main(void)
{
    int passed = 0;

	// strpbrk tests
    char str1[ELEVEN] = "Tie a rope";
    char str2[TWO] = "r";
    char *my = my_strpbrk(str1, str2);
    char *their = strpbrk(str1, str2);
    if (my && their)
        printf("My strpbrk %c(%p); Their %c(%p)",
            *my, &(*my), *their, &(*their));
    else
        printf("Yup, this is NULL, my dudes (strpbrk)");
    if (&(*my) == &(*their))
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");

    char str3[SEVENTEEN] = "Around your neck";
    char str4[FOUR] = "n e";
    my = my_strpbrk(str3, str4);
    their = strpbrk(str3, str4);
    if (my && their)
        printf("My strpbrk %c(%p); Their %c(%p)",
            *my, &(*my), *their, &(*their));
    else
        printf("Yup, this is NULL, my dudes (strpbrk)");
    if (&(*my) == &(*their))
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");

    char str5[THIRTYEIGHT] = "If the fall doen't shutter your spine";
    char str6[FOUR] = "q13";
    my = my_strpbrk(str5, str6);
    their = strpbrk(str5, str6);
    if (my && their)
        printf("My strpbrk %c(%p); Their %c(%p)",
            *my, &(*my), *their, &(*their));
    else
        printf("Yup, this is NULL, my dudes (strpbrk)");
    if (&(*my) == &(*their))
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");


	// strspn tests
    char str7[TEN] = "SUFFOCATE!";
    char str8[FOUR] = "SUF";
    int b = my_strspn(str7, str8);
    int b1 = strspn(str7, str8);
    printf("My strspn %d; Their %d", b, b1);
    if (b == b1)
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");

    char str9[TEN] = "SUFFOCATE!";
    char str10[ONE] = "";
    b = my_strspn(str9, str10);
    b1 = strspn(str9, str10);
    printf("My strspn %d; Their %d", b, b1);
    if (b == b1)
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");

    char str11[ELEVEN] = "SUFFOCATE!";
    char str12[SEVEN] = "qwerty";
    b = my_strspn(str11, str12);
    b1 = strspn(str11, str12);
    printf("My strspn %d; Their %d", b, b1);
    if (b == b1)
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");


	// strcspn tests
    char str13[NINETEEN] = "Ire upon the Earth";
    char str14[TWO] = "q";
    b = my_strcspn(str13, str14);
    b1 = strcspn(str13, str14);
    printf("My strcspn %d; Their %d", b, b1);
    if (b == b1)
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");

    char str15[NINETEEN] = "Ire upon the Earth";
    char str16[TEN] = "the Earth";
    b = my_strcspn(str15, str16);
    b1 = strcspn(str15, str16);
    printf("My strcspn %d; Their %d", b, b1);
    if (b == b1)
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");

    char str17[NINETEEN] = "Ire upon the Earth";
    char str18[SEVENTEEN] = "Ire upontheEarth";
    b = my_strcspn(str17, str18);
    b1 = strcspn(str17, str18);
    printf("My strcspn %d; Their %d", b, b1);
    if (b == b1)
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");

	
	// strchr tests
    char str19[EIGHT] = "Oldlood";
    my = my_strchr(str19, 'd');
    their = strchr(str19, 'd');
    if (my && their)
        printf("My strchr %c(%p); Their %c(%p)",
            *my, &(*my), *their, &(*their));
    else
        printf("Ha-ha, classic. It's NULL (strchr)");
    if (&(*my) == &(*their))
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");

    char str23[EIGHT] = "Oldlood";
    my = my_strchr(str23, 'a');
    their = strchr(str23, 'a');
    if (my && their)
        printf("My strchr %c(%p); Their %c(%p)",
            *my, &(*my), *their, &(*their));
    else
        printf("Ha-ha, classic. It's NULL (strchr)");
    if (&(*my) == &(*their))
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");


	// strrchr tests
    char str20[TWENTYTWO] = "Wolves are at my door";
    my = my_strrchr(str20, 'e');
    their = strrchr(str20, 'e');
    if (my && their)
        printf("My strrchr %c(%p); Their %c(%p)",
            *my, &(*my), *their, &(*their));
    else
        printf("Ha-ha, classic. It's NULL (strchr)");
    if (&(*my) == &(*their))
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");

    char str21[TWENTYEIGHT] = "ULTRAHARDCORE MITISHI x359x";
    my = my_strrchr(str21, '[');
    their = strrchr(str21, '[');
    if (my && their)
        printf("My strrchr %c(%p); Their %c(%p)",
            *my, &(*my), *their, &(*their));
    else
        printf("Ha-ha, classic. It's NULL (strrchr)");
    if (&(*my) == &(*their))
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");

    char str22[SIX] = "Wouch!";
    my = my_strrchr(str22, 'W');
    their = strrchr(str22, 'W');
    if (my && their)
        printf("My strrchr %c(%p); Their %c(%p)",
            *my, &(*my), *their, &(*their));
    else
        printf("Ha-ha, classic. It's NULL (strchr)");
    if (&(*my) == &(*their))
    {
        passed++;
        printf(" PASSED\n");
    }
    else
        printf(" FAULT!\n");


	// Total
    printf("Passed %d of 14\n", passed);

    if (passed == TESTS)
        printf("Congratulations!");
    else
        printf("What? It doesn't work?");

    return 0;
}
