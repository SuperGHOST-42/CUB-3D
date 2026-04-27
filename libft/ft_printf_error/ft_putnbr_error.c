/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:45:33 by jobraga-          #+#    #+#             */
/*   Updated: 2025/08/10 21:46:40 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_error.h"

int	ft_putnbr_error(int nbr)
{
	int		count;

	count = 0;
	if (nbr == -2147483648)
	{
		return (ft_putstr_error("-2147483648"));
	}
	if (nbr < 0)
	{
		count += ft_putchar_error('-');
		count += ft_putnbr_error(nbr * -1);
	}
	if (nbr > 9)
		count += ft_putnbr_error(nbr / 10);
	if (nbr >= 0)
		count += ft_putchar_error(nbr % 10 + '0');
	return (count);
}

int	ft_long_error(long long nbr)
{
	int		count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar_error('-');
		count += ft_putnbr_error(nbr * -1);
	}
	if (nbr > 9)
		count += ft_putnbr_error(nbr / 10);
	if (nbr >= 0)
		count += ft_putchar_error(nbr % 10 + '0');
	return (count);
}
