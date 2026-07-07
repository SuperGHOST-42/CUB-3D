/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:43:06 by arpereir          #+#    #+#             */
/*   Updated: 2026/05/15 17:45:01 by arpereir         ###   ########.fr       */
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

static int	rgb_to_int(t_colors color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	int	y;
	int	color;
	int	ceiling_color;
	int	floor_color;

	y = 0;
	ceiling_color = rgb_to_int(game->textures->ceiling);
	floor_color = rgb_to_int(game->textures->floor);
	while (y < ray->draw_start)
	{
		put_pixel(&game->img, x, y, ceiling_color);
		y++;
	}
	color = WALL_COLOR;
	if (ray->side == 1)
		color = WALL_DARK;
	while (y <= ray->draw_end)
	{
		put_pixel(&game->img, x, y, color);
		y++;
	}
	while (y < SCREEN_H)
	{
		put_pixel(&game->img, x, y, floor_color);
		y++;
	}
}
