/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:24:26 by figomes           #+#    #+#             */
/*   Updated: 2026/06/23 14:23:33 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/cub3d.h"

t_token	check_token_type(char *token)
{
	if (ft_strcmp(token, "NO") == 0)
		return (TOKEN_TEXTURE);
	else if (ft_strcmp(token, "SO") == 0)
		return (TOKEN_TEXTURE);
	else if (ft_strcmp(token, "WE") == 0)
		return (TOKEN_TEXTURE);
	else if (ft_strcmp(token, "EA") == 0)
		return (TOKEN_TEXTURE);
	else if (ft_strcmp(token, "F") == 0)
		return (TOKEN_COLOR);
	else if (ft_strcmp(token, "C") == 0)
		return (TOKEN_COLOR);
	else
		return (TOKEN_INVALID);
}

t_error	parse_texture(char *line, t_game *map, int i)
{
	t_error	err;
	int		start;
	int		len;
	char	*token;
	t_token	token_type;

	err = SUCCESS;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (SUCCESS);
	start = i;
	len = 0;
	while (line[i] != ' ' && line[i] != '\t'
		&& line[i] != '\0' && line[i] != '\n')
	{
		i++;
		len++;
	}
	token = ft_substr(line, start, len);
	if (!token)
		return (ERR_MALLOC);
	token_type = check_token_type(token);
	if (token_type == TOKEN_COLOR)
		err = handle_colors(line + i, token, map);
	else if (token_type == TOKEN_TEXTURE)
		err = handle_textures(line + i, token, map->textures, map);
	else
	{
		return (free(token), ERR_INVALID_TOKEN);
	}
	return (free(token), err);
}

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

void	init_map(char *argv, t_game *map)
{
	char	*line_temp;
	char	*trimmed_line;
	int		map_fd;
	t_error	err;

	err = SUCCESS;
	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		error_msg("The Map couldn't be opened\n", map);
	while (1)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		trimmed_line = ft_strtrim(line_temp, "\n");
		free(line_temp);
		 if (!trimmed_line)
        	continue;
		printf("RAW LINE: [%s]\n", trimmed_line);
		if (map->alloc_tex < 6)
    	{
			if (trimmed_line[0] == '\0')
			{
				free(trimmed_line);
				continue;
			}
       		err = parse_texture(trimmed_line, map, 0);
    	}
    	// 2. after config but before map starts
    	else if (!map->map_started)
		{
			if (trimmed_line[0] == '\0')
			{
				free(trimmed_line);
				continue;
			}
			// primeira linha NÃO vazia começa o mapa
			map->map_started = 1;
			err = add_map_line(map, trimmed_line);
		}
    	// 3. inside map
		else
			err = add_map_line(map, trimmed_line);
		if (err != SUCCESS)
		{
			close(map_fd);
			free(trimmed_line);
			free(line_temp);
			print_error(err, map);
		}
		free(trimmed_line);

	}
	close(map_fd);
}
