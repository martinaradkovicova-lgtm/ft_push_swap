/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:57:47 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/09/26 10:04:10 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str1_len;
	size_t	str2_len;
	size_t	i;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	str1_len = ft_strlen(s1);
	str2_len = ft_strlen(s2);
	new_str = (char *)malloc((str1_len + str2_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	i = -1;
	while (s2[++i] != '\0')
	{
		new_str[(str1_len) + i] = s2[i];
	}
	new_str[(str1_len) + i] = '\0';
	return (new_str);
}
