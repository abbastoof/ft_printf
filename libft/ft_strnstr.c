/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:00:11 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/16 16:03:50 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char	*little, size_t len)
{
	size_t	h_index;
	size_t	l_index;
	char	*hey;

	hey = (char *)big;
	h_index = 0;
	if (!len && *little)
		return (0);
	if (!little[0] || len == 0)
		return (hey);
	while (h_index < len && hey[h_index])
	{
		l_index = 0;
		while (hey[h_index + l_index] && little[l_index]
			&& h_index + l_index < len
			&& hey[h_index + l_index] == little[l_index])
			l_index++;
		if (!little[l_index])
			return (hey + h_index);
		h_index++;
	}
	return ((void *)0);
}
