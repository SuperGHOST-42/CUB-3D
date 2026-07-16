/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 00:00:00 by arpereir          #+#    #+#             */
/*   Updated: 2026/07/16 00:00:00 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	pixel = texture->addr + y * texture->line_len
		+ x * (texture->bpp / 8);
	return (*(unsigned int *)pixel);
}

void	draw_textured_wall(t_game *game, t_ray *ray, int x)
{
	t_img	*texture;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		y;

	texture = get_wall_texture(game, ray);
	tex_x = get_texture_x(game, ray, texture);
	step = (double)texture->height / ray->line_height;
	tex_pos = (ray->draw_start - SCREEN_H / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		put_pixel(&game->img, x, y, get_texture_pixel(texture,
				tex_x, (int)tex_pos));
		tex_pos += step;
		y++;
	}
}
