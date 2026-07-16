/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 00:00:00 by arpereir          #+#    #+#             */
/*   Updated: 2026/07/16 00:00:00 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_key_state(int keycode, t_game *game, int state)
{
	if (keycode == XK_w)
		game->keys.w = state;
	else if (keycode == XK_s)
		game->keys.s = state;
	else if (keycode == XK_a)
		game->keys.a = state;
	else if (keycode == XK_d)
		game->keys.d = state;
	else if (keycode == XK_Left)
		game->keys.left = state;
	else if (keycode == XK_Right)
		game->keys.right = state;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_game(game);
	set_key_state(keycode, game, 1);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	set_key_state(keycode, game, 0);
	return (0);
}

int	render_frame(t_game *game)
{
	struct timeval	time;
	long			now;

	gettimeofday(&time, NULL);
	now = time.tv_sec * 1000L + time.tv_usec / 1000L;
	if (now - game->last_frame_ms < 16)
	{
		usleep(1000);
		return (0);
	}
	game->last_frame_ms = now;
	move_player(game, game->keys.w - game->keys.s,
		game->keys.d - game->keys.a);
	rotate_player(game, game->keys.right - game->keys.left);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
