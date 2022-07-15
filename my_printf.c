#include "main.h"
#include <stdlib.h>

void manage_id(const char *f, va_list my_arg, int i)
{
    int a = 0;

    if (*f == 'i' || *f == 'd') {
        i++;
        a = va_arg(my_arg, int);
        if (a > 0 && *(f-1) == '+')
            my_putchar('+');
        if (a != -2147483648)
            my_put_nbr(a);
        else
            my_putstr("-2147483648");
    }
}

int base_flags(const char *f, va_list my_arg, int i)
{
    int a = 0;

    if (*f == 'c' && i == 0) {
        ++i;
        my_putchar(va_arg(my_arg, int));
    }
    if (*f == 's' && i == 0) {
        ++i;
        my_putstr(va_arg(my_arg, char *));
    }
    manage_id(f, my_arg, i);
    if (*f == '%' && i == 0) {
        my_putchar('%');
    }
    return (0);
}

const char *manage_erro(const char *f) {
    int i = 0;

    while (*f == '0' || *f == '+' || *f == '-')
        f++;
    while (*f == ' ' && *f != '\0') {
        if (*(f+1) != ' ')
            my_putchar(' ');
        f++;
    }
    for (;*f == '#'; i++)
        f++;
    if (i != 0) {
        if (*f == 'o')
            my_putchar('0');
        if (*f == 'x')
            my_putstr("0x");
        if (*f == 'X')
            my_putstr("0X");
    }
    return (f);
}

void manage_erroors(char f, va_list my_arg)
{
    int j = 0;
    char tab_flags[] = "cdisuxXS%pob";

    for (int i = 0; tab_flags[i] != '\0'; i++) {
        if (f == tab_flags[i])
            j = 1;
    }
    if (j == 0) {
        my_putchar('%');
        my_putchar(f);
    }
}

int _printf(const char *f, ...)
{
    va_list my_arg;
    int i = 0;
    const char *compare = 0;

    va_start(my_arg, f);
    for (; *f != '\0'; f++) {
        if (*f == '%' ) {
            f++;
            f = manage_erro(f);
            base_flags(f, my_arg, i);
            manage_base(f, my_arg);
            manage_others(f, my_arg);
            manage_erroors(*f, my_arg);
        } else {
            my_putchar(*f);
        }
    }
    va_end(my_arg);
    return (my_strlen(f));
}
