/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:18:55 by figomes           #+#    #+#             */
/*   Updated: 2025/06/24 16:18:57 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(char format, va_list(args))
{
	if (format == 'c')
		return (ft_putchar_count(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_void(va_arg(args, unsigned long)));
	else if ((format == 'd') | (format == 'i'))
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	else if (format == 'u')
		return (ft_putnbr_u(va_arg(args, int), "0123456789"));
	else if (format == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_putchar_count(format));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	if (str == 0)
		return (0);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			count += ft_format(*str, args);
		}
		else
			count += ft_putchar_count(*str);
		str++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	ft_printf("Adfghhfghfghfghtfg");

	return (0);
	}
*/