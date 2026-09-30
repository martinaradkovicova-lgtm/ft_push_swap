/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:30:01 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/09/26 10:05:18 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_lower(unsigned int x)
{
	int		i;
	int		d;
	int		count;
	char	buf[sizeof(x) * 2];

	if (x == 0)
		return (ft_putchar('0'));
	i = 0;
	while (x != 0)
	{
		d = x & 0xF;
		if (d < 10)
		{
			buf[i++] = (char)('0' + d);
		}
		else
		{
			buf[i++] = (char)('a' + (d - 10));
		}
		x >>= 4;
	}
	count = i;
	while (i-- > 0)
		ft_putchar(buf[i]);
	return (count);
}
