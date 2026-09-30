/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:57:55 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/09/26 10:06:20 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(int n)
{
	size_t	strlen;
	long	num;

	num = n;
	strlen = 0;
	if (num <= 0)
	{
		num = -num;
		strlen++;
	}
	while (num > 0)
	{
		num = num / 10;
		strlen++;
	}
	return (strlen);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*new_str;
	size_t	strlen;

	num = n;
	strlen = ft_count(n);
	new_str = malloc((strlen + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	if (n == 0)
		new_str[0] = '0';
	if (num < 0)
	{
		num = -num;
		new_str[0] = '-';
	}
	new_str[strlen] = '\0';
	while (num > 0)
	{
		strlen--;
		new_str[strlen] = (num % 10) + '0';
		num = num / 10;
	}
	return (new_str);
}
