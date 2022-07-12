#include "main.h"

/**
 * _putchar - print a letter
 * @c: character to print
 * Description: Print every letter of puchar
 * Return: 0
 */
void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 * _printf - Our Own implementation of printf
 * @format: main string to parse
 *
 * Description: Implementation of printf
 * Return: Always 0.
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				_putchar(va_arg(args, int));
			i++;
		} else
			_putchar(format[i]);
		i++;
	}
	va_end(args);
    return (0);
}
