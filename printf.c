#include "main.h"

/**
 * _putstr - print a string
 * @str: string
 * Description: Print every letter of a string
 * Return: 0
 */
void _putstr(char *str)
{
	int i = 0;

	for (; str[i]; i++)
		write(1, &str[i], 1);
}

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

	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				_putchar(va_arg(args, int));
			if (format[i + 1] == 's')
				_putstr(va_arg(args, char *));
			if (format[i + 1] == '%')
				_putchar('%');
			i++;
		} else
			_putchar(format[i]);
		i++;
	}
	va_end(args);
    return (0);
}
