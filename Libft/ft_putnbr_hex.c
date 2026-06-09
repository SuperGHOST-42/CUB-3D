/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:19:21 by figomes           #+#    #+#             */
/*   Updated: 2025/06/24 16:19:22 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex(unsigned long int nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_putnbr_hex(nbr / 16, base);
	count += ft_putchar_count(base[nbr % 16]);
	return (count);
}

/*int	main(void)
{
	int x;
	x = ft_putnbr_hex(50000, "0123456789ABCDEF");
	//printf("\n");
	//printf("%d\n", x);
	return (0);
}
*/