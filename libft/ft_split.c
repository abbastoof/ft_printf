/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:02:54 by mtoof             #+#    #+#             */
/*   Updated: 2022/11/17 15:00:30 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(char const *str, char c)
{
	int	i;
	int	words_count;

	words_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			words_count++;
		i++;
	}
	return (words_count);
}

static void	ft_freemem(char **str, int index)
{
	while (index--)
		free(str[index]);
	free(str);
}

static int	ft_words_len(const char *s, char c, int index)
{
	int	len;

	len = 0;
	while (s[index] != c && s[index])
	{
		index++;
		len++;
	}
	return (len);
}

static char	**ft_words(char **new_str, const char *s, char c, int words_count)
{
	int	count;
	int	index;
	int	word_size;

	count = 0;
	index = 0;
	while (count < words_count)
	{
		while (s[index] == c)
			index++;
		word_size = ft_words_len(s, c, index);
		new_str[count] = ft_substr(s, index, word_size);
		if (!new_str[count])
		{
			ft_freemem(new_str, count);
			return (NULL);
		}
		index = index + word_size;
		count++;
	}
	return (new_str);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	int		words_count;

	if (!s)
		return (NULL);
	words_count = ft_words_count(s, c);
	new_str = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!new_str)
		return (NULL);
	new_str = ft_words(new_str, s, c, words_count);
	new_str[words_count] = 0;
	return (new_str);
}
