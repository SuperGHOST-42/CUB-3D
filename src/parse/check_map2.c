/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:06:07 by figomes           #+#    #+#             */
/*   Updated: 2026/08/04 21:47:46 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	get_tile(char **map, int y, int x)
{
	if (y < 0 || map[y] == NULL)
		return (' ');
	if (x < 0)
		return (' ');
	if (x >= (int)ft_strlen(map[y]))
		return (' ');
	return (map[y][x]);
}

static void	check_neighbors(t_game *game, char **map, int y, int x)
{
	if (get_tile(map, y - 1, x) == ' ')
		error_msg("Error, invalid map", game);
	if (get_tile(map, y + 1, x) == ' ')
		error_msg("Error, invalid map", game);
	if (get_tile(map, y, x - 1) == ' ')
		error_msg("Error, invalid map", game);
	if (get_tile(map, y, x + 1) == ' ')
		error_msg("Error, invalid map", game);
}

int	validate_walls(t_game *game, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (ft_strchr("0NSEW", map[y][x]))
				check_neighbors(game, map, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

int	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line[i] == '\0' || line[i] == '\n');
}

void	trim_end_empty_lines(char **map)
{
	int	last;

	if (!map)
		return ;
	last = 0;
	while (map[last])
		last++;
	last--;
	while (last >= 0 && is_empty_line(map[last]))
	{
		free(map[last]);
		map[last] = NULL;
		last--;
	}
}
