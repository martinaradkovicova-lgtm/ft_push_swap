/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:57:52 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/09/26 10:04:25 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_strings(char const *s, char c)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			result++;
		i++;
	}
	return (result);
}

static char	**ft_free_array(char **array, size_t allocated_count)
{
	size_t	i;

	i = 0;
	while (i < allocated_count)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char	**ft_allocate_words(char **array, char const *s, char c)
{
	size_t	i;
	size_t	y;
	size_t	word_size;

	i = 0;
	y = 0;
	word_size = 0;
	while (s[i] != '\0' || word_size > 0)
	{
		if (s[i] != c && s[i] != '\0')
			word_size++;
		else if (word_size > 0)
		{
			array[y] = ft_substr(s, (i - word_size), word_size);
			if (!array[y])
				return (ft_free_array(array, y));
			y++;
			word_size = 0;
		}
		if (s[i] != '\0')
			i++;
	}
	array[y] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**new_array;
	size_t	strings_nb;

	if (!s)
		return (NULL);
	strings_nb = ft_count_strings(s, c);
	new_array = malloc((strings_nb + 1) * sizeof(char *));
	if (!new_array)
		return (NULL);
	return (ft_allocate_words(new_array, s, c));
}
