#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "holberton.h"
#include <stdio.h>
/**
 *_printf- main for checking to see if there is a conversion
 * @format: char pointer
 * Return: number of characters printed
 */


int _printf(const char *format, ...)
{
	int i = 0, index = 0, *ip = &index;
	int (*get_format)(va_list, char *, int *);

	char buffer[1024];
	va_list list;

	va_start(list, format);
	if (format == NULL)
		return (-1);
	while (format != NULL && format[i])
	{
		if (format[i] != '%' && format[i - 1] != '%')
		{
			buffer[*ip] = format[i];
			(*ip)++;
		}
		else if (format[i] == '%' && format[i - 1] != '%')
		{
			get_format = formatter(format[i + 1]);
			if (get_format == NULL)
				return (-1);
			else
				get_format(list, buffer, ip);
		}
		else if (format[i] != '%' && format[i - 1] == '%' && format[i - 2] == '%')
		{
			buffer[*ip] = format[i];
			(*ip)++;
		}
		i++;
	}
	va_end(list);
	write(1, buffer, *ip);
	return (index);
}
