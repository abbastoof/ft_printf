/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:17 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/16 16:14:26 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_ptr;
	char	*src_ptr;
	int		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	while (i < (int)n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}
