/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:38:29 by jobraga-          #+#    #+#             */
/*   Updated: 2025/08/10 21:48:40 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_error.h"

static int	ft_check(char const c, va_list args)
{
	int		i;

	i = 0;
	if (c == 'p')
		i += ft_add_error(va_arg(args, unsigned long long));
	else if (c == 'c')
		i += ft_putchar_error(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		i += ft_putnbr_hexa_error(c, va_arg(args, unsigned int));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr_error(va_arg(args, int));
	else if (c == 'u')
		i += ft_long_error(va_arg(args, unsigned int));
	else if (c == 's')
		i += ft_putstr_error(va_arg(args, char *));
	else if (c == '%')
		return (ft_putchar_error('%'));
	return (i);
}

int	ft_printf_error(const char *format, ...)
{
	va_list		args;
	int			i;
	int			cc;

	cc = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			cc += ft_check(format[i + 1], args);
			i++;
		}
		else
			cc += ft_putchar_error(format[i]);
		i++;
	}
	va_end(args);
	return (cc);
}
