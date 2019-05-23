#include <stdio.h>
#include <string.h>

/*
 * Функция возвращает указатель на первый символ в строке, на которую
 * указывает str1, совпадающий с каким-нибудь из символов строки, на которую
 * указывает str2. Нулевые символы в конце строк в рассмотрение не включаются.
 * Если совпадений нет, возвращается NULL.
 */
char *my_strpbrk(const char *str1, const char *str2)
{
    int i = 0, j = 0;
    while (str1[i])
    {
        while (str2[j])
        {
            if (str2[j] == str1[i])
                return (char*)str1 + i;
            j++;
        }
        j = 0;
        i++;
    }
    return NULL;
}

/*
 * Функция возвращает количество символов в начале строки с указателем
 * str1, в число которых входят только символы, имеющиеся в строке с указателем
 * str2. Другими словами, для строки str1 функция strspn() возвращает значение
 * индекса первого символа из числа символов, не входящих в строку str2.
 */
size_t my_strspn(const char *str1, const char *str2)
{
    int i = 0, j = 0, num = 0;
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
            j = 0;
            i++;
        }
        else
            return num;
    }
    return num;
}

/* Функция strcspn выполняет поиск первого вхождения в строку string1 любого
 * из символов строки string2, и возвращает количество символов до найденного
 * первого вхождения.
 */
size_t my_strcspn(const char *str1, const char *str2)
{
    int i = 0, j = 0, num = 0;
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
        j = 0;
        i++;
        num++;
    }
    return num;
}

/* Функция strchr выполняет поиск первого вхождения символа symbol в
 * строку string. Возвращает указатель на первое вхождение символа в
 * строке. Завершающий нулевой символ считается частью Си-строки.
 * Таким образом, он также может быть найден для получения указателя
 * на конец строки.
 */
char *my_strchr(const char *string, int symbol)
{
    int i = 0;
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

/*
 * Функция ищет последнее вхождение символа symbol в строку string. Возвращает
 * указатель на последнее вхождение символа в строке string. Завершающий
 * нулевой символ считается частью строки. Таким образом, он также может быть
 * найден для получения указателя на конец строки.
 */
char *my_strrchr(const char *string, int symbol)
{
    int i = 0;
    while (string[i])
        i++;
    i++;
    while (i+1)
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
    char str1[11] = "Tie a rope";
    char str2[2] = "r";
    char *my = my_strpbrk(str1, str2);
    char *their = strpbrk(str1, str2);
    if (my && their)
        printf("My strpbrk %c(%p); Their %c(%p)", *my, &(*my), *their, &(*their));
    else
        printf("Yup, this is NULL, my dudes (strpbrk)");
    if (&(*my) == &(*their))
        printf(" PASSED\n");
    else
        printf(" FAULT!\n");

    char str3[17] = "Around your neck";
    char str4[4] = "n e";
    my = my_strpbrk(str3, str4);
    their = strpbrk(str3, str4);
    if (my && their)
        printf("My strpbrk %c(%p); Their %c(%p)", *my, &(*my), *their, &(*their));
    else
        printf("Yup, this is NULL, my dudes (strpbrk)");
    if (&(*my) == &(*their))
        printf(" PASSED\n");
    else
        printf(" FAULT!\n");

    char str5[38] = "If the fall doen't shutter your spine";
    char str6[4] = "q13";
    my = my_strpbrk(str5, str6);
    their = strpbrk(str5, str6);
    if (my && their)
        printf("My strpbrk %c(%p); Their %c(%p)", *my, &(*my), *their, &(*their));
    else
        printf("Yup, this is NULL, my dudes (strpbrk)");
    if (&(*my) == &(*their))
        printf(" PASSED\n");
    else
        printf(" FAULT!\n");


    char str7[10] = "SUFFOCATE!";
    char str8[4] = "SUF";
    int b = my_strspn(str7, str8);
    int b1 = strspn(str7, str8);
    printf("My strspn %d; Their %d", b, b1);
    if (b == b1)
        printf(" PASSED\n");
    else
        printf(" FAULT!\n");

    char str9[10] = "SUFFOCATE!";
    char str10[1] = "";
    b = my_strspn(str9, str10);
    b1 = strspn(str9, str10);
    printf("My strspn %d; Their %d", b, b1);
    if (b == b1)
        printf(" PASSED\n");
    else
        printf(" FAULT!\n");

    char str11[11] = "SUFFOCATE!";
    char str12[7] = "qwerty";
    b = my_strspn(str11, str12);
    b1 = strspn(str11, str12);
    printf("My strspn %d; Their %d", b, b1);
    if (b == b1)
        printf(" PASSED\n");
    else
        printf(" FAULT!\n");


    char str13[19] = "Ire upon the Earth";
    char str14[2] = "q";
    b = my_strcspn(str13, str14);
    b1 = strcspn(str13, str14);
    printf("My strcspn %d; Their %d", b, b1);
    if (b == b1)
        printf(" PASSED\n");
    else
        printf(" FAULT!\n");

    char str15[19] = "Ire upon the Earth";
    char str16[10] = "the Earth";
    b = my_strcspn(str15, str16);
    b1 = strcspn(str15, str16);
    printf("My strcspn %d; Their %d", b, b1);
    if (b == b1)
        printf(" PASSED\n");
    else
        printf(" FAULT!\n");

    char str17[19] = "Ire upon the Earth";
    char str18[17] = "Ire upontheEarth";
    b = my_strcspn(str17, str18);
    b1 = strcspn(str17, str18);
    printf("My strcspn %d; Their %d", b, b1);
    if (b == b1)
        printf(" PASSED\n");
    else
        printf(" FAULT!\n");


    char str19[8] = "Oldlood";
    my = my_strchr(str19, 'd');
    their = strchr(str19, 'd');
    if (my && their)
        printf("My strrchr %c(%p); Their %c(%p)", *my, &(*my), *their, &(*their));
    else
        printf("Ha-ha, classic. It's NULL (strchr)");
    if (&(*my) == &(*their))
        printf(" PASSED\n");
    else
        printf(" FAULT!\n");

    char str20[22] = "Wolves are at my door";
    my = my_strrchr(str20, 'e');
    their = strrchr(str20, 'e');
    if (my && their)
        printf("My strrchr %c(%p); Their %c(%p)", *my, &(*my), *their, &(*their));
    else
        printf("Ha-ha, classic. It's NULL (strchr)");
    if (&(*my) == &(*their))
        printf(" PASSED\n");
    else
        printf(" FAULT!\n");

    char str21[28] = "ULTRAHARDCORE MITISHI x359x";
    my = my_strrchr(str21, '[');
    their = strrchr(str21, '[');
    if (my && their)
        printf("My strrchr %c(%p); Their %c(%p)", *my, &(*my), *their, &(*their));
    else
        printf("Ha-ha, classic. It's NULL (strchr)");
    if (&(*my) == &(*their))
        printf(" PASSED\n");
    else
        printf(" FAULT!\n");

    return 0;
}