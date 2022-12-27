/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:59:28 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/16 16:16:52 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	found(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static char	*blank_set(char *new_str, const char *s1, int s1_len)
{
	new_str = malloc(s1_len + 1);
	ft_strlcpy(new_str, s1, s1_len + 1);
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		s1_len;
	int		begin;
	int		end;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	begin = 0;
	new_str = (NULL);
	if (!set)
		blank_set(new_str, s1, s1_len);
	while (s1[begin] && found(s1[begin], set) == 0)
		begin++;
	begin--;
	end = s1_len - 1;
	while (end > begin && found(s1[end], set) == 0)
		end--;
	new_str = (char *)malloc(end - begin + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1 + begin + 1, end - begin + 1);
	return (new_str);
}
