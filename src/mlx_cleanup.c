/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 00:00:00 by arpereir          #+#    #+#             */
/*   Updated: 2026/07/16 00:00:00 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	destroy_images(t_game *game)
{
	if (!game->mlx)
		return ;
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->north.img)
		mlx_destroy_image(game->mlx, game->north.img);
	if (game->south.img)
		mlx_destroy_image(game->mlx, game->south.img);
	if (game->east.img)
		mlx_destroy_image(game->mlx, game->east.img);
	if (game->west.img)
		mlx_destroy_image(game->mlx, game->west.img);
}

static void	destroy_mlx(t_game *game)
{
	destroy_images(game);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	close_game(t_game *game)
{
	destroy_mlx(game);
	clean_game(game);
	exit(0);
	return (0);
}

void	exit_mlx_error(t_game *game, char *message)
{
	write(2, message, ft_strlen(message));
	destroy_mlx(game);
	clean_game(game);
	exit(1);
}
