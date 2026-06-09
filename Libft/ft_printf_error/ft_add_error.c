/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:27:59 by jobraga-          #+#    #+#             */
/*   Updated: 2025/08/10 21:48:35 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_error.h"

int	ft_add_error(unsigned long long address)
{
	int		count;

	count = 0;
	if (!address)
		return (ft_putstr_error("(nil)"));
	else
	{
		count += ft_putstr_error("0x");
		count += ft_putnbr_hexa_error('x', address);
	}
	return (count);
}
