#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *my_hexa_final(va_list my_arg, long b)
{
    long value = va_arg(my_arg, long);
    char *new_value_base = malloc(sizeof(char) * 10000);
    int result = 0;
    int i = 0;

    for (; value >= b; i++) {
        result = value % b;
        new_value_base[i] = my_return_hexa(result);
        value = value / b;
    }
    result = value;
    new_value_base[i] = my_return_hexa(result);
    new_value_base[i + 1] = '\0';
    new_value_base = my_revstr(new_value_base);
    return (new_value_base);
}

char my_return_hexa(int result)
{
    char table[] = "abcdef";

    if (result >= 10 && result <= 15) {
        return (table[result - 10]);
    }
    if (result >= 0 && result <= 9)
        return (result + 48);
    return (result);
}

char *transformer(va_list my_arg, int b)
{
    long value = va_arg(my_arg, long);
    char *new_value_base = malloc(sizeof(char) *10000);
    int result = 0;
    int i = 0;

    for (; value >= b; i++) {
        result = value % b;
        new_value_base[i] = my_return_hexa(result);
        value = value / b;
    }
    new_value_base[i] = my_return_hexa(value);
    new_value_base[i + 1] = '\0';
    new_value_base = my_revstr(new_value_base);
    return (new_value_base);
}

int manage_base(const char *f, va_list my_arg)
{
    if (*f == 'X' || *f == 'x' || *f == 'o' || *f == 'b') {
        if (*f == 'x') {
            my_putstr(transformer(my_arg, 16));
        }
        if (*f == 'X') {
            my_putstr(my_strupcase(transformer(my_arg, 16)));
        }
        if (*f == 'o') {
            my_putstr(transformer(my_arg, 8));
        }
        if (*f == 'b') {
            my_putstr(transformer(my_arg, 2));
        }
    }
    return (EXIT_SUCCESS);
}
