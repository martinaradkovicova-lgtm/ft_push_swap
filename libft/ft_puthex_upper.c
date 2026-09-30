/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:30:03 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/09/26 10:05:13 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_upper(unsigned int y)
{
	int		i;
	int		d;
	int		count;
	char	buf[sizeof(y) * 2];

	if (y == 0)
		return (ft_putchar('0'));
	i = 0;
	while (y != 0)
	{
		d = y & 0xF;
		if (d < 10)
		{
			buf[i++] = (char)('0' + d);
		}
		else
		{
			buf[i++] = (char)('a' + (d - 10));
		}
		y >>= 4;
	}
	count = i;
	while (i-- > 0)
		ft_putchar(ft_toupper(buf[i]));
	return (count);
}
