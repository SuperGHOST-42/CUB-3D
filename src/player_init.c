/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 00:00:00 by arpereir          #+#    #+#             */
/*   Updated: 2026/08/04 19:09:17 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_player_direction(t_game *game, char direction)
{
	if (direction == 'N')
	{
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
	}
	else if (direction == 'S')
	{
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
	}
	else if (direction == 'W')
	{
		game->player.dir_x = -1;
		game->player.plane_y = -0.66;
	}
	else if (direction == 'E')
	{
		game->player.dir_x = 1;
		game->player.plane_y = 0.66;
	}
}

static void	set_player(t_game *game, int x, int y)
{
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	set_player_direction(game, game->full_map[y][x]);
	game->full_map[y][x] = '0';
}

void	init_player(t_game *game)
{
	int	y;
	int	x;

	if (!game->full_map)
		error_msg("Map is missing\n", game);
	y = 0;
	while (game->full_map[y] != NULL)
	{
		x = 0;
		while (game->full_map[y][x] != '\0')
		{
			if (is_player(game->full_map[y][x]))
			{
				game->players++;
				set_player(game, x, y);
			}
			x++;
		}
		y++;
	}
	if (game->players != 1)
		error_msg("Invalid number of players\n", game);
}
