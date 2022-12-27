/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:59:27 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/16 16:01:02 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num_str;
	int		n_len;
	long	number;

	number = n;
	n_len = nlen(n);
	num_str = (char *)malloc(sizeof(char) * n_len + 1);
	if (!num_str)
		return (NULL);
	num_str[n_len--] = '\0';
	if (number < 0)
	{
		num_str[0] = '-';
		number = -number;
	}
	while (number >= 10)
	{
		num_str[n_len--] = (number % 10) + '0';
		number = number / 10;
	}
	num_str[n_len] = number + '0';
	return (num_str);
}
