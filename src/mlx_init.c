/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:49:07 by arpereir          #+#    #+#             */
/*   Updated: 2026/05/15 18:01:45 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	render_loop()
{
	return (0);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			SCREEN_W,
			SCREEN_H,
			"cub3D");
	game->img.img = mlx_new_image(game->mlx,
			SCREEN_W,
			SCREEN_H);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bpp,
			&game->img.line_len,
			&game->img.endian);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.img, 0, 0);
	mlx_loop_hook(game->mlx, render_loop, game);
	mlx_loop(game->mlx);
}