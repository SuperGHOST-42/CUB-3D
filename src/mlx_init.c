/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:49:07 by arpereir          #+#    #+#             */
/*   Updated: 2026/07/15 16:50:36 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	load_texture(t_game *game, t_img *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path,
			&texture->width, &texture->height);
	if (!texture->img)
		exit_mlx_error(game, "Error\ntexture load failed\n");
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
	if (!texture->addr)
		exit_mlx_error(game, "Error\ntexture data failed\n");
}

static void	load_textures(t_game *game)
{
	load_texture(game, &game->north, game->textures->north_path);
	load_texture(game, &game->south, game->textures->south_path);
	load_texture(game, &game->east, game->textures->east_path);
	load_texture(game, &game->west, game->textures->west_path);
}

static void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_mlx_error(game, "Error\nmlx_init failed\n");
	game->win = mlx_new_window(game->mlx, SCREEN_W, SCREEN_H, "cub3D");
	if (!game->win)
		exit_mlx_error(game, "Error\nmlx_new_window failed\n");
}

static void	init_frame_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	if (!game->img.img)
		exit_mlx_error(game, "Error\nmlx_new_image failed\n");
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	if (!game->img.addr)
		exit_mlx_error(game, "Error\nmlx_get_data_addr failed\n");
}

void	init_mlx(t_game *game)
{
	ft_bzero(&game->keys, sizeof(t_keys));
	game->last_frame_ms = 0;
	init_window(game);
	init_frame_image(game);
	load_textures(game);
	render_frame(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, close_game, game);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
}
