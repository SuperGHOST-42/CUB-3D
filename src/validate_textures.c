/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:06:41 by figomes           #+#    #+#             */
/*   Updated: 2026/06/23 14:25:16 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/cub3d.h"

void	check_command(int argc, char *argv)
{
	int	parameter_len;

	if (argc > 2)
	{
		ft_printf("Too many arguments.\n");
		exit(0);
	}
	if (argc < 2)
	{
		ft_printf("The Map file is missing.\n");
		exit(0);
	}
	parameter_len = ft_strlen(argv);
	if (!ft_strnstr(&argv[parameter_len - 4], ".cub", 4))
	{
		ft_printf("Map file extention is wrong\n");
		exit(0);
	}
}

t_error	validate_config(t_game *map)
{
	if (!map->textures->north_path)
		return (ERR_MISSING_VALUE);
	if (!map->textures->south_path)
		return (ERR_MISSING_VALUE);
	if (!map->textures->west_path)
		return (ERR_MISSING_VALUE);
	if (!map->textures->east_path)
		return (ERR_MISSING_VALUE);
	if (map->textures->floor.r == -1
		|| map->textures->floor.g == -1
		|| map->textures->floor.b == -1)
		return (ERR_MISSING_VALUE);
	if (map->textures->ceiling.r == -1
		|| map->textures->ceiling.g == -1
		|| map->textures->ceiling.b == -1)
		return (ERR_MISSING_VALUE);
	return (SUCCESS);
}
