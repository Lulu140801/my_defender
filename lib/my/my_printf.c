/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** display an other string
*/

#include "../../include/my.h"
#include <stdarg.h>

void my_printf(char *s, ...)
{
    va_list ap;
    va_start(ap, s);
    int a = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        a = i + 1;
        if ( s[i] == '%' && (s[a] == '%' || s[a] == 'c' \
        || s[a] == 's' || s[a] == 'd')) {
            print_charc(ap, s, i);
            print_str(ap, s, i);
            print_deci(ap, s, i);
            i++;
        }
        else {
            my_putchar(s[i]);
        }
    }
    va_end(ap);
}

void print_charc(va_list ap, char *s, int i)
{
    if (s[i + 1] == 'c') {
        char c = va_arg(ap, int);
        my_putchar(c);
    }
}

void print_str(va_list ap, char *s, int i)
{
    if (s[i + 1] == 's') {
        char *s = va_arg(ap, char*);
        my_putstr(s);
    }
}

void print_deci(va_list ap, char *s, int i)
{
    if (s[i + 1] == 'd') {
        int j = va_arg(ap, int);
        my_put_nbr(j);
    }
}