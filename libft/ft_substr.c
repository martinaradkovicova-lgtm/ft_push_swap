/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:57:43 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/09/26 10:03:45 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	str;

	if (!s)
		return (NULL);
	str = ft_strlen(s);
	if (start >= str)
		return (ft_strdup(""));
	if (len > str - start)
		len = str - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL )
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
