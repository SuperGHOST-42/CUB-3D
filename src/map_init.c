/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:24:26 by figomes           #+#    #+#             */
/*   Updated: 2026/06/25 15:04:36 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/cub3d.h"

t_error	add_map_line(t_game *map, char *line)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (map->map_height + 2));
	if (!new_map)
		return (ERR_MALLOC);
	i = 0;
	while (i < map->map_height)
	{
		new_map[i] = map->full_map[i];
		i++;
	}
	new_map[i] = ft_strdup(line);
	if (!new_map[i])
		return (ERR_MALLOC);
	new_map[i + 1] = NULL;
	free(map->full_map);
	map->full_map = new_map;
	map->map_height++;
	return (SUCCESS);
}

void	sanitize_line(char *line)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i])
		i++;
	if (i > 0 && line[i - 1] == '\n')
		line[i - 1] = '\0';
}

void	init_map(char *argv, t_game *map)
{
	char	*line_temp;
	int		map_fd;
	t_error	err;

	err = SUCCESS;
	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		error_msg("The Map couldn't be opened\n", map);
	while (1)
	{
		line_temp = get_next_line(map_fd);
		if (!line_temp)
			break ;
		sanitize_line(line_temp);
		printf("RAW LINE: [%s]\n", line_temp);
		// CONFIG PHASE
		if (map->alloc_tex < 6)
		{
			if (line_temp[0] == '\0')
			{
				free(line_temp);
				continue ;
			}
			err = parse_texture(line_temp, map, 0);
		}
		// BEFORE MAP START
		else if (!map->map_started)
		{
			if (line_temp[0] == '\0')
			{
				free(line_temp);
				continue ;
			}
			map->map_started = 1;
			err = add_map_line(map, line_temp);
		}
		// MAP PHASE
		else
		{
			// 👉 SEM ERRO AQUI — só copiar
			err = add_map_line(map, line_temp);
		}
		if (err != SUCCESS)
		{
			close(map_fd);
			free(line_temp);
			print_error(err, map);
		}

		free(line_temp);
	}
	close(map_fd);
}
