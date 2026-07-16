/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:00:29 by arpereir          #+#    #+#             */
/*   Updated: 2026/05/15 17:06:01 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/macro.h"

int	is_wall(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0)
		return (1);
	map_x = (int)x;
	map_y = (int)y;
	if (map_y >= game->map_height || !game->full_map[map_y])
		return (1);
	if (map_x >= (int)ft_strlen(game->full_map[map_y]))
		return (1);
	return (game->full_map[map_y][map_x] != '0');
}

static int	can_move(t_game *game, double x, double y)
{
	return (!is_wall(game, x - PLAYER_RADIUS, y - PLAYER_RADIUS)
		&& !is_wall(game, x + PLAYER_RADIUS, y - PLAYER_RADIUS)
		&& !is_wall(game, x - PLAYER_RADIUS, y + PLAYER_RADIUS)
		&& !is_wall(game, x + PLAYER_RADIUS, y + PLAYER_RADIUS));
}

void	move_player(t_game *game, int forward, int side)
{
	double	new_x;
	double	new_y;
	double	speed;

	if (!forward && !side)
		return ;
	speed = SPEED;
	if (forward && side)
		speed *= 0.707106;
	new_x = game->player.x + (game->player.dir_x * forward
			- game->player.dir_y * side) * speed;
	new_y = game->player.y + (game->player.dir_y * forward
			+ game->player.dir_x * side) * speed;
	if (can_move(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move(game, game->player.x, new_y))
		game->player.y = new_y;
}

void	rotate_player(t_game *game, int direction)
{
	double	angle;
	double	old_x;

	if (!direction)
		return ;
	angle = ROT_SPEED * direction;
	old_x = game->player.dir_x;
	game->player.dir_x = old_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	old_x = game->player.plane_x;
	game->player.plane_x = old_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_x * sin(angle)
		+ game->player.plane_y * cos(angle);
}
