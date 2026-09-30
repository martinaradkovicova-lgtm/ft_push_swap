/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:29:58 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/09/26 10:04:46 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	uintptr_t	cast;
	int			i;
	int			d;
	int			count;
	char		buf[sizeof(cast) * 2];

	cast = (uintptr_t)ptr;
	if (cast == 0)
		return (ft_putstr("(nil)"));
	i = 0;
	count = ft_putstr("0x");
	while (cast != 0)
	{
		d = cast & 0xF;
		if (d < 10)
			buf[i++] = (char)('0' + d);
		else
			buf[i++] = (char)('a' + (d - 10));
		cast >>= 4;
	}
	count += i;
	while (i-- > 0)
		ft_putchar(buf[i]);
	return (count);
}
