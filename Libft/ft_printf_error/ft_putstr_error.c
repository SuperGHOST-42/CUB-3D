/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:43:06 by jobraga-          #+#    #+#             */
/*   Updated: 2025/08/10 21:48:50 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_error.h"

int	ft_putstr_error(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		write (2, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar_error(str[i]);
		i++;
	}
	return (i);
}
