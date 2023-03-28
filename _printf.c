#include "main.h"
#include <stdarg.h>

/**
 * check_format - checks if there is a valid format specifier
 * @format: possible valid format specifier
 * Return: pointer to valid function or NULL
 */
int (*check_format(const char *format))(va_list)
{
	int i = 0;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"b", print_b},
		{"u", print_u},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"p", print_p},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};

	for (; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
			break;
	}
	return (p[i].f);
}

/**
 * _printf - function for format printing
 * @format: list of arguments to printing
 * Return: Number of characters to printing
 */

int _printf(const char *format, ...)
{
<<<<<<< HEAD
	int i, printed = 0, printed_chars = 0;

	int flags, width, precision, size, buff_ind = 0;

	va_list list;

	char buffer[BUFF_SIZE];
=======
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, counter = 0;
>>>>>>> b5ca96ec93bbc35ec982c5af082c8c9501231e16


	if (format == NULL)
		return (-1);

<<<<<<< HEAD
	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
		{
			if (format[i] != '%')
		{

		buffer[buff_ind++] = format[i];

	if (buff_ind == BUFF_SIZE)

		print_buffer(buffer, &buff_ind);

	/* write(1, &format[i], 1);*/

	printed_chars++;

	}

	else

	{

	print_buffer(buffer, &buff_ind);

	flags = get_flags(format, &i);

	width = get_width(format, &i, list);

	precision = get_precision(format, &i, list);

	size = get_size(format, &i);

	++i;

	printed = handle_print(format, &i, list, buffer,

	flags, width, precision, size);

	if (printed == -1)

	return (-1);

	printed_chars += printed;
	}
		}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);

}

/**
*print_buffer - Prints the contents of the buffer if it exist
* @buffer: Array of chars
* @buff_ind: Index at which to add next char, represents the length.
*/

void print_buffer(char buffer[], int *buff_ind)

{

	if (*buff_ind > 0)

		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
=======
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			counter++;
			i++;
			continue;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				counter++;
				i += 2;
				continue;
			}
			else
			{
				f = check_format(&format[i + 1]);
				if (f == NULL)
					return (-1);
				i += 2;
				counter += f(ap);
				continue;
			}
		}
		i++;
	}
	va_end(ap);
	return (counter);
>>>>>>> b5ca96ec93bbc35ec982c5af082c8c9501231e16
}
