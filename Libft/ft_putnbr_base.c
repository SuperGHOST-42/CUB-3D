/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:19:12 by figomes           #+#    #+#             */
/*   Updated: 2025/06/24 16:19:14 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	basesize;
	unsigned int	n;
	int				count;

	count = 0;
	basesize = ft_strlen_count(base);
	if (nbr < 0)
	{
		n = -nbr;
		count += ft_putchar_count('-');
	}
	else
		n = nbr;
	if (n >= basesize)
	{
		count += ft_putnbr_base(n / basesize, base);
	}
	count += ft_putchar_count(base[n % basesize]);
	return (count);
}

/*int	main(void)
{
	ft_putnbr_base(0, "0123456789");
}*/