#ifndef __MYHEADERPRINTF__
#define __MYHEADERPRINTF__

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void manage_id(const char *f, va_list my_arg, int i);
const char *manage_erro(const char *f);
char *convert_base_octa(int value, int b);
void no_printable(char *str);
int my_put_nbr_a(unsigned int nb);
int my_put_nbr(int nb);
char *my_hexa_final(va_list my_arg, long b);
int manage_others(const char *f, va_list my_arg);
char *transformer(va_list my_arg, int b);
char my_return_hexa(int result) ;
int my_printf(const char *f, ...);
int base_flags(const char *f, va_list my_arg, int i);
int manage_base(const char *f, va_list my_arg);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strupcase(char *str);
int manage_errors(char f, int i);
int _printf(const char *format, ...);
#endif
