/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:23:55 by figomes           #+#    #+#             */
/*   Updated: 2025/06/24 16:23:57 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

void	flood_fill(int x, int y, int *flag)
{
	if (map()->test[y][x] == '1' || map()->test[y][x] == 'P'
		|| map()->test[y][x] == 'D' || map()->test[y][x] == 'X')
		return ;
	else if (map()->test[y][x] == '0')
		map()->test[y][x] = 'P';
	else if (map()->test [y][x] == 'C')
		map()->test[y][x] = 'D';
	else if (map()->test[y][x] == 'E')
	{
		(*flag)++;
		return ;
	}
	flood_fill(x + 1, y, flag);
	flood_fill(x - 1, y, flag);
	flood_fill(x, y + 1, flag);
	flood_fill(x, y - 1, flag);
}

int	check_collec(char **mapa)
{
	int	x;
	int	y;

	y = 0;
	while (mapa[y])
	{
		x = 0;
		while (mapa[y][x])
		{
			if (mapa[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	fill_flood(void)
{
	int			flag;
	int			x;
	int			y;

	x = (int)objs()->player.pos_x;
	y = (int)objs()->player.pos_y;
	flag = 0;
	flood_fill(x, y, &flag);
	flood_fill(x + 1, y, &flag);
	flood_fill(x - 1, y, &flag);
	flood_fill(x, y + 1, &flag);
	flood_fill(x, y - 1, &flag);
	if (flag == 0 || !check_collec(map()->test))
		error_msg("Path not valid.");
	free_map(map()->test);
	return (0);
}
