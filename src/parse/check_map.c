/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:23:46 by figomes           #+#    #+#             */
/*   Updated: 2026/07/13 14:09:57 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	has_empty_line_inside(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_empty_line(map[i]))
			error_msg("Empty Line detected", game);
		i++;
	}
	return (0);
}

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S'
		|| c == 'E' || c == 'W');
}

int	check_map_chars(t_game *game)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (game->full_map[i])
	{
		j = 0;
		while (game->full_map[i][j] && game->full_map[i][j] != '\n')
		{
			if (!is_valid_char(game->full_map[i][j]))
				error_msg("Invalid character in map", game);
			if (ft_strchr("NSEW", game->full_map[i][j]))
			{
				player++;
				game->player_or = game->full_map[i][j];
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		error_msg("Map must contain exactly one player", game);
	return (0);
}

int	validate_line(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] != '1')
			error_msg("Error, invalid map", game);
		j = ft_strlen(map[i]) - 1;
		if (map[i][j] == '\n')
			j--;
		while (j >= 0 && map[i][j] == ' ')
			j--;
		if (map[i][j] != '1')
			error_msg("Error, invalid map", game);
		i++;
	}
	return (0);
}

void	validade_map(t_game *game)
{
	if (!game ->full_map)
		error_msg("Map is NULL", game);
	check_map_chars(game);
	has_empty_line_inside(game, game->full_map);
	validate_line(game, game->full_map);
	validate_walls(game, game->full_map);
}
