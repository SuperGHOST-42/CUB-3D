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

#include "../includes/cub.h"
#include "../includes/macro.h"

static int	can_move(t_game *game, double x, double y)
{
	if (game->map[(int)y][(int)x] == '1')
		return (0);
	return (1);
}

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = SPEED;
	new_x = game->player.x + game->player.dir_x * speed;
	new_y = game->player.y + game->player.dir_y * speed;
	if (can_move(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move(game, game->player.x, new_y))
		game->player.y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = SPEED;
	new_x = game->player.x - game->player.dir_x * speed;
	new_y = game->player.y - game->player.dir_y * speed;
	if (can_move(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move(game, game->player.x, new_y))
		game->player.y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = SPEED;
	new_x = game->player.x - (game->player.plane_x * speed);
	new_y = game->player.y - (game->player.plane_y * speed);
	if (can_move(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move(game, game->player.x, new_y))
		game->player.y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = SPEED;
	new_x = game->player.x + (game->player.plane_x * speed);
	new_y = game->player.y + (game->player.plane_y * speed);
	if (can_move(game, new_x, game->player.y))
		game->player.x = new_x;
	if (can_move(game, game->player.x, new_y))
		game->player.y = new_y;
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = ROT_SPEED;
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed)
		- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed)
		+ game->player.plane_y * cos(rot_speed);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = ROT_SPEED;
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(-rot_speed)
		- game->player.dir_y * sin(-rot_speed);
	game->player.dir_y = old_dir_x * sin(-rot_speed)
		+ game->player.dir_y * cos(-rot_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(-rot_speed)
		- game->player.plane_y * sin(-rot_speed);
	game->player.plane_y = old_plane_x * sin(-rot_speed)
		+ game->player.plane_y * cos(-rot_speed);
}