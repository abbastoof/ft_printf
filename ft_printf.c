/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:26:18 by atoof             #+#    #+#             */
/*   Updated: 2022/12/16 20:53:39 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_search_format(t_print *args, const char *format)
{
	int returnn;
	int	index;

	index = 0;
	returnn = 0;
	while (!"udcsupxX%")
	{
		if(format[index] == '.')
			args->point = 1;
			index++;
		if(format[index] == '-')
			args->dash = 1;
			index++;
		if(format[index] == ' ')
			args->space = 1;
			index++;
		if(format[index] < 0)
			args->sign = 1;
		if(format[index] > 0)
			args->sign = 1;
	}
}

int	ft_check_format(t_print args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += printchar(va_arg(args.arg, int));
	else if (format == 's')
		print_length += printstr(va_arg(args.arg, char *));
	else if (format == 'p')
		print_length += print_ptr(va_arg(args.arg, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += printnbr(va_arg(args.arg, int));
	else if (format == 'u')
		print_length += print_unsigned(va_arg(args.arg, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += print_hex(va_arg(args.arg, unsigned int), format);
	else if (format == '%')
		print_length += printpercent();
	return (print_length);
}

t_print	*ft_initialise(t_print *init)
{
	//set everything to false
	init->length = 0;
	init->dash = 0;
	init->width = 0;
	init->is_zero = 0;
	init->percentage = 0;
	init->point = 0;
	init->precision = 0;
	init->sign = 0;
	init->space = 0;
	init->zeropadding = 0;
	return (init);
}

int	ft_printf(const char *format, ...)
{
	t_print	argument;
	int		i;
	int		printf_length;

	argument.arg = (t_print *)malloc(sizeof(t_print));
	if (!argument.arg)
		return (-1);
	ft_initialise(argument.arg);
	va_start(argument.arg, format);
	i = 0;
	printf_length = 0;
	while (format[i]) // string exists
	{
		if (format[i] == '%') //if the char is %
		{
			printf_length += ft_check_format(argument, format[i + 1]);
			i++;
		}
		else
			printf_length += write(1, &format[i], 1);
		i++;
	}
	va_end(argument.arg);
	printf_length += (argument.length);
	free (argument);
	return (printf_length);
}
