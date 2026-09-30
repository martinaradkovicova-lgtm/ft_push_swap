/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:29:49 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/09/26 10:04:30 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsign(unsigned int u)
{
	int	count;

	count = 0;
	if (u >= 10)
	{
		count += ft_putunsign(u / 10);
	}
	count += ft_putchar((u % 10) + '0');
	return (count);
}
