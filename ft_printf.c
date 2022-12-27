/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:42:22 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/22 19:47:10 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_int(va_list args, int counter)
{
	long	i;

	i = va_arg(args, int);
	if (i < 0)
	{
		counter += ft_putchar('-');
		i = -i;
	}
	counter += ft_convert(i, 10, 0);
	return (counter);
}

static int	ft_check_format(va_list args, const char *format)
{
	int	length;

	length = 0;
	if (*format == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (*format == 'X')
		length += ft_convert_number(va_arg(args, unsigned int), 16, 0);
	else if (*format == 'x')
		length += ft_convert_number(va_arg(args, unsigned int), 16, 32);
	else if (*format == 'd' || *format == 'i')
		length += ft_check_int(args, length);
	else if (*format == 'u')
		length += ft_convert_number(va_arg(args, unsigned int), 10, 0);
	else if (*format == 'p')
	{
		length += ft_putstr("0x");
		length += ft_convert_number((size_t)va_arg(args, void *), 16, 32);
	}
	else if (*format == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *tmp, ...)
{
	int		length;
	va_list	args;

	length = 0;
	va_start(args, tmp);
	while (*tmp)
	{
		if (*tmp != '%')
			length += ft_putchar(*tmp);
		else if (*tmp == '%')
		{
			tmp++;
			length += ft_check_format(args, tmp);
		}
		if (!*tmp)
			return (length);
		tmp++;
	}
	va_end(args);
	return (length);
}
