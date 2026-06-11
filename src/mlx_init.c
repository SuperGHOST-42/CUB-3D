/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:49:07 by arpereir          #+#    #+#             */
/*   Updated: 2026/06/09 12:50:44 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render_loop()
{
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
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.img, 0, 0);
	mlx_loop_hook(game->mlx, render_loop, game);
	mlx_loop(game->mlx);
}
