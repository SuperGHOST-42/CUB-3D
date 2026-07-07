/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:49:07 by arpereir          #+#    #+#             */
/*   Updated: 2026/07/01 02:22:57 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	close_game(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	clean_game(game);
	exit(0);
	return (0);
}

static int	render_frame(t_game *game)
{
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

static int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_game(game);
	else if (keycode == XK_w)
		move_forward(game);
	else if (keycode == XK_s)
		move_backward(game);
	else if (keycode == XK_a)
		move_left(game);
	else if (keycode == XK_d)
		move_right(game);
	else if (keycode == XK_Left)
		rotate_right(game);
	else if (keycode == XK_Right)
		rotate_left(game);
	render_frame(game);
	return (0);
}

static void	exit_mlx_error(char *message)
{
	write(2, message, ft_strlen(message));
	exit(1);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_mlx_error("Error\n mlx_init failed\n");
	game->win = mlx_new_window(game->mlx,
			SCREEN_W,
			SCREEN_H,
			"cub3D");
	if (!game->win)
		exit_mlx_error("Error\n mlx_new_window failed\n");
	game->img.img = mlx_new_image(game->mlx,
			SCREEN_W,
			SCREEN_H);
	if (!game->img.img)
		exit_mlx_error("Error\n mlx_new_image failed\n");
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bpp,
			&game->img.line_len,
			&game->img.endian);
	if (!game->img.addr)
		exit_mlx_error("Error\n mlx_get_data_addr failed\n");
	render_frame(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, close_game, game);
	mlx_loop(game->mlx);
}
