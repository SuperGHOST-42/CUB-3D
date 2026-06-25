/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:23:14 by figomes           #+#    #+#             */
/*   Updated: 2026/06/25 14:43:51 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/cub3d.h"

void	free_textures(t_textures *textures)
{
	if (!textures)
		return ;
	if (textures->north_path)
		free(textures->north_path);
	if (textures->south_path)
		free(textures->south_path);
	if (textures->east_path)
		free(textures->east_path);
	if (textures->west_path)
		free(textures->west_path);
	free(textures);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clean_game(t_game *game)
{
	if (!game)
		return ;
	if (game->textures)
		free_textures(game->textures);
	if (game->full_map)
		free_map(game->full_map);
	if (game->map_path)
		free(game->map_path);
}

void	free_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
}
