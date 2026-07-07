/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:23:46 by figomes           #+#    #+#             */
/*   Updated: 2026/07/07 14:52:19 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_empty_line(char *line)
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

void	validade_map(t_game *game)
{
	has_empty_line_inside(game, game->full_map);
	check_map_chars(game);
}