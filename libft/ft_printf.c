/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:28:58 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/09/26 10:03:15 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_process_fmt(char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(*args, void *));
	else if (c == 'd')
		count += ft_putnbr(va_arg(*args, int));
	else if (c == 'i')
		count += ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		count += ft_putunsign(va_arg(*args, unsigned int));
	else if (c == 'x')
		count += ft_puthex_lower(va_arg(*args, unsigned int));
	else if (c == 'X')
		count += ft_puthex_upper(va_arg(*args, unsigned int));
	else if ((c == '%') || (c == '\0'))
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	index;
	int		count;

	index = 0;
	count = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			count += ft_process_fmt(format[index + 1], &args);
			index++;
		}
		else
			count += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (count);
}
