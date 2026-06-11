/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:22:35 by figomes           #+#    #+#             */
/*   Updated: 2026/06/11 08:09:25 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_textures(t_textures *t)
{
	printf("TEXTURES:\n");
	printf("NO: %s\n", t->north_path);
	printf("SO: %s\n", t->south_path);
	printf("WE: %s\n", t->west_path);
	printf("EA: %s\n", t->east_path);
}

void	print_colors(char *name, t_colors c)
{
	printf("%s: R=%d G=%d B=%d\n", name, c.r, c.g, c.b);
}

void	print_map(char **map)
{
	int	i;

	if (!map)
	{
		printf("Map is NULL\n");
		return ;
	}
	i = 0;
	printf("===== MAP =====\n");
	while (map[i])
	{
		printf("[%d] %s\n", i, map[i]);
		i++;
	}
	printf("==============\n");
}

void	print_game(t_game *g)
{
	printf("\n===== GAME DEBUG =====\n");
	print_textures(g->textures);
	print_colors("FLOOR", g->textures->floor);
	print_colors("CEILING", g->textures->ceiling);
	print_map(g->full_map);
	printf("======================\n");
}
