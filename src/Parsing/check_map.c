/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:23:46 by figomes           #+#    #+#             */
/*   Updated: 2025/06/24 16:23:48 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	count_map(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->colums)
		{
			if (!ft_strchr("CEP01X", map->full[y][x]))
				error_msg("Wrong game parameters.");
			else if (map->full[y][x] == COLLECTABLE)
				map->collectables++;
			else if (map->full[y][x] == M_EXIT)
				map->exit++;
			else if (map->full[y][x] == PLAYER)
				map->players++;
			x++;
		}
		y++;
	}
}

void	verify_parameters(t_map *map)
{
	if (map->collectables == 0)
		error_msg("There are no Collectables!");
	else if (map->exit != 1)
		error_msg("Invalid number of Exits.");
	else if (map->players != 1)
		error_msg("Invalid Player quantity.");
}
