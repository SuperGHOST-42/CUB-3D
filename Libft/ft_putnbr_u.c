/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:19:30 by figomes           #+#    #+#             */
/*   Updated: 2025/06/24 16:19:31 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_u(unsigned int nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 10)
	{
		count += ft_putnbr_u(nbr / 10, base);
	}
	count += ft_putchar_count(base[nbr % 10]);
	return (count);
}

/*int	main(void)
{
	unsigned char test[] = "0123456789";
	ft_putnbr_u(42, test);
}*/