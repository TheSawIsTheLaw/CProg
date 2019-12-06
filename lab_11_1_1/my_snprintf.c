#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>
#include "my_snprintf.h"

#define ZERO 48
#define NINE 57

int my_snprintf(char *restrict buf, size_t n, const char *restrict format, ...)
{
    if (!buf || !format || n <= 0)
        return 0;

    va_list argptr;
    va_start(argptr, format);

    DEB("Заход")
    size_t i = 0, b_i = 0;

    while (*(format + i) != '\0' && b_i < n)
    {
        DEB("Проход")
        if (*(format + i) == '%')
        {
            i++;
            if (*(format + i) == '\0')
                continue;
            else if (*(format + i) == 'd')
            {
                DEB("%d")
                int num = va_arg(argptr, int);
                if (num == 0)
                {
                    *(buf + b_i) = '0';
                    b_i++;
                    i++;
                    continue;
                }
                int mas_num[10], q_mas = 0;
                if (num < q_mas)
                {
                    num *= -1;
                    *(buf + b_i) = '-';
                    b_i++;
                    if (b_i >= n)
                        continue;
                }
                if (num == 0)
                    i++;
                while (num != 0)
                {
                    mas_num[q_mas] = num % 10;
                    q_mas++;
                    num = num / 10;
                }
                q_mas--;
                for (int j = q_mas; j >= 0; j--)
                {
                    *(buf + b_i) = (char)(mas_num[j] + ZERO);
                    b_i++;
                    if (b_i >= n)
                        continue;
                }
            }
            else if (*(format + i) == 'i')
            {
                DEB("%i")
                int num = va_arg(argptr, int);
                if (num == 0)
                {
                    i++;
                    *(buf + b_i) = '0';
                    b_i++;
                    continue;
                }
                int mas_num[10], q_mas = 0;
                if (num < q_mas)
                {
                    num *= -1;
                    *(buf + b_i) = '-';
                    b_i++;
                    if (b_i >= n)
                        continue;
                }
                while (num != 0)
                {
                    mas_num[q_mas] = num % 10;
                    q_mas++;
                    num = num / 10;
                }
                q_mas--;
                for (int j = q_mas; j >= 0; j--)
                {
                    *(buf + b_i) = (char)(mas_num[j] + ZERO);
                    b_i++;
                    if (b_i >= n)
                        continue;
                }
            }
            else if (*(format + i) == 'x')
            {
                DEB("%x")
                uint32_t num = va_arg(argptr, uint32_t);
                uint32_t mas[8];
                if (num == 0)
                {
                    *(buf + b_i) = '0';
                    b_i++;
                    continue;
                }
                short q_mas = 0;
                while (num != 0 && q_mas < 8)
                {
                    mas[q_mas] = num % 16;
                    num = num / 16;
                }
                q_mas--;

                char hex_pudge[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
                for (int j = q_mas; j >= 0; j--)
                {
                    *(buf + b_i) = hex_pudge[mas[j]];
                    b_i++;
                    if (b_i >= n)
                        continue;
                }
            }
            else if (*(format + i) == 'l')
            {
                i++;
                if (*(format + i) == '\0')
                    continue;
                else if (*(format + i) == 'd')
                {
                    DEB("%ld")
                    uint32_t num = va_arg(argptr, uint32_t);
                    if (num == 0)
                    {
                        i++;
                        *(buf + b_i) = '0';
                        b_i++;
                        continue;
                    }
                    short mas_num[19], q_mas = 0;
                    if (num < q_mas)
                    {
                        num *= -1;
                        *(buf + b_i) = '-';
                        b_i++;
                        if (b_i >= n)
                            continue;
                    }
                    while (num != 0)
                    {
                        mas_num[q_mas] = num % 10;
                        q_mas++;
                        num = num / 10;
                    }
                    q_mas--;
                    for (int j = q_mas; j >= 0; j--)
                    {
                        *(buf + b_i) = (char)(mas_num[j] + ZERO);
                        b_i++;
                        if (b_i >= n)
                            continue;
                    }
                }
                else if (*(format + i) == 'i')
                {
                    DEB("%li")
                    uint32_t num = va_arg(argptr, uint32_t);
                    if (num == 0)
                    {
                        i++;
                        *(buf + b_i) = '0';
                        b_i++;
                        continue;
                    }
                    short mas_num[19], q_mas = 0;
                    if (num < q_mas)
                    {
                        num *= -1;
                        *(buf + b_i) = '-';
                        b_i++;
                        if (b_i >= n)
                            continue;
                    }
                    while (num != 0)
                    {
                        mas_num[q_mas] = num % 10;
                        q_mas++;
                        num = num / 10;
                    }
                    q_mas--;
                    for (int j = q_mas; j >= 0; j--)
                    {
                        *(buf + b_i) = (char)(mas_num[j] + ZERO);
                        b_i++;
                        if (b_i >= n)
                            continue;
                    }
                }
                else if (*(format + i) == 'x')
                {
                    DEB("%lx")
                    uint32_t num = va_arg(argptr, uint32_t);
                    uint32_t mas[20];
                    if (num == 0)
                    {
                        *(buf + b_i) = '0';
                        b_i++;
                        continue;
                    }
                    short q_mas = 0;
                    while (num != 0 && q_mas < 20)
                    {
                        mas[q_mas] = num % 16;
                        num = num / 16;
                    }
                    q_mas--;

                    char hex_pudge[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
                    for (int j = q_mas; j >= 0; j++)
                    {
                        *(buf + b_i) = hex_pudge[mas[j]];
                        b_i++;
                        if (b_i >= n)
                            continue;
                    }
                }
            }
            i++;
        }
        else
        {
            *(buf + b_i) = *(format + i);
            b_i++;
            i++;
        }
    }

    if (b_i < n)
        *(buf + b_i) = '\0';
    else
        *(buf + b_i - 1) = '\0';

    va_end(argptr);

    return b_i;
}

