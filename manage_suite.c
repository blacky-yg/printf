#include "main.h"
#include <stdlib.h>

int manage_others(const char *f, va_list my_arg)
{
    unsigned int  u = 0;
    char *str = malloc(sizeof(char) * 100);

    if (*f == 'u') {
        u = (unsigned int)va_arg(my_arg, unsigned int);
        my_put_nbr_a(u);
    }
    if (*f == 'p') {
        my_putstr("0x");
        my_putstr(my_hexa_final(my_arg, 16));
    }
    if (*f == 'S') {
        str = va_arg(my_arg, char *);
        no_printable(str);
    }
}

void no_printable(char *str)
{
    int j = 0;
    int k = 0;
    char *new_str;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 127 || str[i] < 32) {
            my_putchar('\\');
            my_putstr(convert_base_octa(str[i], 8));
        } else {
            my_putchar(str[i]);
        }
    }
}

char *convert_base_octa(int value, int b)
{
    char *new_value_base = malloc(sizeof(char) *6);
    int result = 0;
    int i = 0;

    for (; value >= b; i++) {
        result = value % b;
        new_value_base[i] = my_return_hexa(result) ;
        value = value / b;
    }
    result = value;
    new_value_base[i] = my_return_hexa(result);
    new_value_base[i + 1] = '\0';
    if (my_strlen(new_value_base) == 2)
        my_putchar('0');
    if (my_strlen(new_value_base) == 1)
        my_putstr("00");
    new_value_base = my_revstr(new_value_base);
    return (new_value_base);
}
