/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:33:28 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/16 16:00:40 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc_mem;
	size_t	size_alloc;

	size_alloc = size * count;
	if (count > 0 && size > 0)
		if (size_alloc % count != 0 || size_alloc % size != 0)
			return (NULL);
	alloc_mem = (void *)malloc(sizeof(char) * size_alloc);
	if (!alloc_mem)
		return (NULL);
	ft_bzero(alloc_mem, size_alloc);
	return (alloc_mem);
}
