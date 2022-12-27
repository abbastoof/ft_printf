/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:03:17 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/16 16:02:28 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	char		*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (src_ptr == dst_ptr)
		return (dst);
	if (src_ptr < dst_ptr)
	{
		src_ptr = src_ptr + len - 1;
		dst_ptr = dst_ptr + len - 1;
		while (len--)
			*dst_ptr-- = *src_ptr--;
	}
	else
	{
		while (len--)
			*dst_ptr++ = *src_ptr++;
	}
	return (dst);
}
