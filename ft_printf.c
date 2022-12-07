/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:26:18 by atoof             #+#    #+#             */
/*   Updated: 2022/12/07 17:46:56 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_print
{
	va_list	arg;
	int		wdt;
	int		len;
}			t_print;

t_print	*ft_initialise(t_print *init)
{
	init->len = 0;
	init->wdt = 0;
	return (init);
}

int	ft_printf(const char *format, ...)
{
	t_print	*argument;
	int		i;

	argument = (t_print *)malloc(sizeof(t_print));
	if (!argument)
		return (-1);
	ft_initialise(argument);
	va_start(argument->arg, format);
	i = -1;
	while (format[++i])
	{
		if (*format == '%')
		{
			ft_search_format(argument, format, i++);
		}
	}
}
