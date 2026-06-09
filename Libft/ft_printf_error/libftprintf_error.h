/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_error.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:28:27 by jobraga-          #+#    #+#             */
/*   Updated: 2025/08/10 21:29:53 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_ERROR_H
# define LIBFTPRINTF_ERROR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_putchar_error(int c);
int	ft_putstr_error(char *str);
int	ft_putnbr_error(int nbr);
int	ft_long_error(long long nbr);
int	ft_putnbr_hexa_error(char c, unsigned long long hexa);
int	ft_add_error(unsigned long long address);
int	ft_printf_error(const char *format, ...);

#endif