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

static t_img	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dir_x < 0)
		return (&game->west);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		return (&game->east);
	if (ray->side == 1 && ray->ray_dir_y < 0)
		return (&game->north);
	return (&game->south);
}

static int	get_texture_x(t_game *game, t_ray *ray, t_img *texture)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * texture->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

static int	get_texture_pixel(t_img *texture, int x, int y)
{
	char	*pixel;

	if (x < 0)
		x = 0;
	if (x >= texture->width)
		x = texture->width - 1;
	if (y < 0)
		y = 0;
	if (y >= texture->height)
		y = texture->height - 1;
	pixel = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(unsigned int *)pixel);
}

static void	draw_textured_wall(t_game *game, t_ray *ray, int x)
{
	t_img	*texture;
	double			step;
	double			tex_pos;
	int				tex_x;
	int				tex_y;
	int				y;

	texture = get_wall_texture(game, ray);
	tex_x = get_texture_x(game, ray, texture);
	step = (double)texture->height / ray->line_height;
	tex_pos = (ray->draw_start - SCREEN_H / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		put_pixel(&game->img, x, y, get_texture_pixel(texture, tex_x, tex_y));
		y++;
	}
}

void	draw_column(t_game *game, t_ray *ray, int x)
{
	int	y;
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
	draw_textured_wall(game, ray, x);
	y = ray->draw_end + 1;
	while (y < SCREEN_H)
	{
		put_pixel(&game->img, x, y, floor_color);
		y++;
	}
}
