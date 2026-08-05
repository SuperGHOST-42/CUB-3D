/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:43:06 by arpereir          #+#    #+#             */
/*   Updated: 2026/08/05 16:39:26 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_W || y < 0 || y >= SCREEN_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	ceiling_color;
	int	floor_color;

	y = 0;
	ceiling_color = (game->textures->ceiling.r << 16)
		| (game->textures->ceiling.g << 8) | game->textures->ceiling.b;
	floor_color = (game->textures->floor.r << 16)
		| (game->textures->floor.g << 8) | game->textures->floor.b;
	while (y < ray->draw_start)
	{
		put_pixel(&game->img, x, y, ceiling_color);
		y++;
	}
	draw_textured_wall(game, ray, x);
	y = ray->draw_end + 1;
	while (y < SCREEN_H)
	{
		put_pixel(&game->img, x, y, floor_color);
		y++;
	}
}
