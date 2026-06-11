/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:54:30 by figomes           #+#    #+#             */
/*   Updated: 2026/06/11 15:24:30 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/cub3d.h"

void	init_textures(t_textures *textures)
{
	textures->north_path = NULL;
	textures->south_path = NULL;
	textures->east_path = NULL;
	textures->west_path = NULL;

	textures->floor.r = -1;
	textures->floor.g = -1;
	textures->floor.b = -1;

	textures->ceiling.r = -1;
	textures->ceiling.g = -1;
	textures->ceiling.b = -1;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->full_map = NULL;
	game->map_path = NULL;
	game->players = 0;
	game->map_alloc = FALSE;
	game->textures = NULL;
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		return ;
	init_textures(game->textures);
}

char	*ft_str_doublepointer(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1); 
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

void	error_msg(char *message, t_game *game)
{
	ft_printf("Error\n %s", message);
	clean_game(game);
	exit (1);
}