/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 17:59:21 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/09/26 10:06:31 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*result;

	if (nelem != 0 && elsize > (size_t)-1 / nelem)
		return (NULL);
	if (nelem == 0 || elsize == 0)
		return (malloc(0));
	result = malloc(nelem * elsize);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, nelem * elsize);
	return (result);
}
