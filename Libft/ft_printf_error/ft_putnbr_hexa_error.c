/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:40:27 by jobraga-          #+#    #+#             */
/*   Updated: 2025/08/10 21:42:28 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_error.h"

int	ft_putnbr_hexa_error(char c, unsigned long long hexa)
{
	int		count;

	count = 0;
	if (c == 'x')
	{
		if (hexa > 15)
			count += ft_putnbr_hexa_error('x', (hexa / 16));
		if ((hexa % 16) >= 10)
			count += ft_putchar_error((hexa % 16) - 10 + 'a');
		if ((hexa % 16) <= 9)
			count += ft_putchar_error(hexa % 16 + '0');
	}
	if (c == 'X')
	{
		if (hexa > 15)
			count += ft_putnbr_hexa_error('X', (hexa / 16));
		if ((hexa % 16) >= 10)
			count += ft_putchar_error((hexa % 16) - 10 + 'A');
		if ((hexa % 16) <= 9)
			count += ft_putchar_error(hexa % 16 + '0');
	}
	return (count);
}
