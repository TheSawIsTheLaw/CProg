#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>
#include <limits.h>
#include "my_snprintf.h"

#define ZERO 48
#define NINE 57

int my_snprintf(char *restrict buf, size_t n, const char *restrict format, ...)
{
    if (!format || n > INT_MAX)
        return -1;

    va_list argptr;
    va_start(argptr, format);

    DEB("Заход")
    size_t i = 0, b_i = 0;

    while (*(format + i))
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
                    if (b_i < n && buf && n)
                        *(buf + b_i) = '0';
                    b_i++;
                    i++;
                    continue;
                }
                int mas_num[10], q_mas = 0;
                if (num < q_mas)
                {
                    num *= -1;
                    if (b_i < n && buf && n)
                        *(buf + b_i) = '-';
                    b_i++;
                }
                if (num == 0)
                    i++;
                // А теперь я хочу вот что сказать.
                // Это ненормально.
                // Спасибо за внимание.
                // ПЕРЕПОЛНЕНИЕ
                if (num < 0)
                {
                    mas_num[q_mas] = 8;
                    q_mas++;
                    num++;
                    num *= -1;
                    num = num / 10;
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
                    if (b_i < n && buf && n)
                        *(buf + b_i) = (char)(mas_num[j] + ZERO);
                    b_i++;
                }
            }
            else if (*(format + i) == 'i')
            {
                DEB("%i")
                int num = va_arg(argptr, int);
                if (num == 0)
                {
                    if (b_i < n && buf && n)
                        *(buf + b_i) = '0';
                    b_i++;
                    i++;
                    continue;
                }
                int mas_num[10], q_mas = 0;
                if (num < q_mas)
                {
                    num *= -1;
                    if (b_i < n && buf && n)
                        *(buf + b_i) = '-';
                    b_i++;
                }
                if (num == 0)
                    i++;
                // А теперь я хочу вот что сказать.
                // Это ненормально.
                // Спасибо за внимание.
                // ПЕРЕПОЛНЕНИЕ
                if (num < 0)
                {
                    mas_num[q_mas] = 8;
                    q_mas++;
                    num++;
                    num *= -1;
                    num = num / 10;
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
                    if (b_i < n && buf && n)
                        *(buf + b_i) = (char)(mas_num[j] + ZERO);
                    b_i++;
                }
            }
            else if (*(format + i) == 'x')
            {
                DEB("%x")
                uint32_t num = va_arg(argptr, uint32_t);
                printf("!%u!", num);
                uint32_t mas[8];
                if (num == 0)
                {
                    i++;
                    if (b_i < n && buf && n)
                        *(buf + b_i) = '0';
                    b_i++;
                    continue;
                }
                short q_mas = 0;
                while (num != 0 && q_mas < 8)
                {
                    mas[q_mas] = num % 16;
                    num = num / 16;
                    q_mas++;
                }
                q_mas--;

                char hex_pudge[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
                for (int j = q_mas; j >= 0; j--)
                {
                    if (b_i < n && buf && n)
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
                    int64_t num = va_arg(argptr, int64_t);
                    if (num == 0)
                    {
                        if (b_i < n && buf && n)
                            *(buf + b_i) = '0';
                        b_i++;
                        i++;
                        continue;
                    }
                    int mas_num[20], q_mas = 0;
                    if (num < q_mas)
                    {
                        num *= -1;
                        if (b_i < n && buf && n)
                            *(buf + b_i) = '-';
                        b_i++;
                    }
                    if (num == 0)
                        i++;
                    // А теперь я хочу вот что сказать.
                    // Это ненормально.
                    // Спасибо за внимание.
                    // ПЕРЕПОЛНЕНИЕ
                    if (num < 0)
                    {
                        mas_num[q_mas] = 8;
                        q_mas++;
                        num++;
                        num *= -1;
                        num = num / 10;
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
                        if (b_i < n && buf && n)
                            *(buf + b_i) = (char)(mas_num[j] + ZERO);
                        b_i++;
                    }
                }
                else if (*(format + i) == 'i')
                {
                    DEB("%li")
                    int64_t num = va_arg(argptr, int64_t);
                    if (num == 0)
                    {
                        if (b_i < n && buf && n)
                            *(buf + b_i) = '0';
                        b_i++;
                        i++;
                        continue;
                    }
                    int mas_num[20], q_mas = 0;
                    if (num < q_mas)
                    {
                        num *= -1;
                        if (b_i < n && buf && n)
                            *(buf + b_i) = '-';
                        b_i++;
                    }
                    if (num == 0)
                        i++;
                    // А теперь я хочу вот что сказать.
                    // Это ненормально.
                    // Спасибо за внимание.
                    // ПЕРЕПОЛНЕНИЕ
                    if (num < 0)
                    {
                        mas_num[q_mas] = 8;
                        q_mas++;
                        num++;
                        num *= -1;
                        num = num / 10;
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
                        if (b_i < n && buf && n)
                            *(buf + b_i) = (char)(mas_num[j] + ZERO);
                        b_i++;
                    }
                }
                else if (*(format + i) == 'x')
                {
                    DEB("%lx")
                    uint64_t num = va_arg(argptr, uint64_t);
                    uint64_t mas[16];
                    if (num == 0)
                    {
                        i++;
                        if (b_i < n && buf && n)
                            *(buf + b_i) = '0';
                        b_i++;
                        continue;
                    }
                    short q_mas = 0;
                    while (num != 0 && q_mas < 16)
                    {
                        mas[q_mas] = num % 16;
                        num = num / 16;
                        q_mas++;
                    }
                    q_mas--;

                    char hex_pudge[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
                    for (int j = q_mas; j >= 0; j--)
                    {
                        if (b_i < n && buf && n)
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
            if (b_i < n && buf && n)
                *(buf + b_i) = *(format + i);
            b_i++;
            i++;
        }
    }

    if (b_i < n && buf && n)
        *(buf + b_i) = '\0';
    else if (buf && n)
        *(buf + n - 1) = '\0';
    va_end(argptr);

    return b_i;
}

