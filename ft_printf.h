/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:13:52 by atoof             #+#    #+#             */
/*   Updated: 2022/12/16 02:22:20 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_print
{
	va_list	arg;
	int		length; //(return value)
	int		precision;
    int     width;
	int		is_zero;
	int		sign; //pos or neg
	int		zeropadding; //"%02d"
	int		point; //.
	int		percentage; //%
	int		dash; //-
	int		space; //space flag ' ' 
}			t_print;

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
