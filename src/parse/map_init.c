/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:24:26 by figomes           #+#    #+#             */
/*   Updated: 2026/07/27 14:13:11 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static t_error	handle_line(t_game *map, char *line)
{
	if (map->alloc_tex < 6)
	{
		if (line[0] == '\0')
			return (SUCCESS);
		return (parse_texture(line, map, 0));
	}
	if (!map->map_started)
	{
		if (line[0] == '\0')
			return (SUCCESS);
		map->map_started = 1;
	}
	return (add_map_line(map, line));
}

static void	check_error(t_error err, int fd, char *line, t_game *map)
{
	if (err != SUCCESS)
	{
		close(fd);
		free(line);
		print_error(err, map);
	}
}

void	init_map(char *argv, t_game *map)
{
	char	*line;
	int		fd;
	t_error	err;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_msg("The Map couldn't be opened\n", map);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		sanitize_line(line);
		err = handle_line(map, line);
		if (err == SUCCESS && line[0] == '\0')
		{
			free(line);
			continue ;
		}
		check_error(err, fd, line, map);
		free(line);
	}
	close(fd);
}
