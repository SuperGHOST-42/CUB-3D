/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:54:30 by figomes           #+#    #+#             */
/*   Updated: 2026/06/25 14:45:13 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->alloc_tex = 0;
	game->win = NULL;
	init_img(&game->img);
	init_img(&game->north);
	init_img(&game->south);
	init_img(&game->east);
	init_img(&game->west);
	game->full_map = NULL;
	game->map_path = NULL;
	game->players = 0;
	game->map_started = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	game->map_alloc = FALSE;
	game->textures = NULL;
	game->map_height = 0;
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
	ft_printf("Error: %s\n", message);
	clean_game(game);
	exit (1);
}

void	print_error(t_error err, t_game *game)
{
	if (err == ERR_MALLOC)
		printf("Memory allocation failed\n");
	else if (err == ERR_INVALID_FORMAT)
		printf("Invalid format\n");
	else if (err == ERR_DUP_TEXTURE)
		printf("Duplicate texture definition\n");
	else if (err == ERR_DUP_COLOR)
		printf("Duplicate color definition\n");
	else if (err == ERR_INVALID_TOKEN)
		printf("Invalid token\n");
	else if (err == ERR_INVALID_RGB)
		printf("Invalid RGB value\n");
	else if (err == ERR_MISSING_VALUE)
		printf("Missing value\n");
	else if (err == ERR_MAP_OPEN_FAIL)
		printf("Failed to open map file\n");
	else
		printf("Unknown error\n");
	clean_game(game);
	exit(2);
}
