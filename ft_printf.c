/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:26:18 by atoof             #+#    #+#             */
/*   Updated: 2022/12/08 21:16:15 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_print
{
	va_list	arg;
	int		length; //(return value)
	int		precision;
	int		is_zero;
	int		sign; //pos or neg
	int		zeropadding; //"%02d"
	int		point; //.
	int		percentage; //%
	int		dash; //-
	int		space; //space flag ' ' 
}			t_print;

t_print	*ft_initialise(t_print *init)
{
	init->length = 0;
	init->dash = 0;
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
	t_print	*argument;

	argument = (t_print *)malloc(sizeof(t_print));
	if (!argument)
		return (-1);
	ft_initialise(argument);
	va_start(argument->arg, format);
	while (*format) // string exists
	{
		if (format == '%') //if the char is %
			format = ft_search_format(argument, *format++);
		else
			ft_putchar_fd(*format++, 1);
		if (!format) 
		{
			ft_putstr_fd("(null)", 7);
			va_end(argument->arg);
			free (argument);
			return (argument->length);
		}
	}
	va_end(argument->arg);
	return (argument->length);
}
