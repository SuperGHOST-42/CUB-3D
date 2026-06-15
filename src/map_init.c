/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:24:26 by figomes           #+#    #+#             */
/*   Updated: 2026/06/15 14:31:51 by figomes          ###   ########.fr       */
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

t_error	handle_textures(char *line, char *token, t_textures *textures)
{
	int		i;
	int		start;
	int		len;
	char	*str;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (ERR_MISSING_VALUE);
	start = i;
	len = 0;
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0' && line[i] != '\n')
	{
		i++;
		len++;
	}
	str = ft_substr(line, start, len);
	if (!str)
		return (ERR_MALLOC);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (free(str), ERR_INVALID_FORMAT);
		i++;
	}
	if (ft_strcmp(token, "NO") == 0)
	{
		if (textures->north_path != NULL)
			return (free(str), ERR_DUP_TEXTURE);
		textures->north_path = str;
	}
	else if (ft_strcmp(token, "SO") == 0)
	{
		if (textures->south_path != NULL)
			return (free(str), ERR_DUP_TEXTURE);
		textures->south_path = str;
	}
	else if (ft_strcmp(token, "WE") == 0)
	{
		if (textures->west_path != NULL)
			return (free(str), ERR_DUP_TEXTURE);
		textures->west_path = str;
	}
	else if (ft_strcmp(token, "EA") == 0)
	{
		if (textures->east_path != NULL)
			return (free(str), ERR_DUP_TEXTURE);
		textures->east_path = str;
	}
	return (SUCCESS);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_error	parse_rgb(char *value, t_colors *color)
{
	char	**rgb;
	int		i;
	t_error	err;

	i = 0;
	err = SUCCESS;
	rgb = ft_split(value, ',');
	if (!rgb)
		return (ERR_MALLOC);
	while (rgb[i])
		i++;
	if (i != 3)
		return (free(rgb), ERR_INVALID_FORMAT);
	if (!is_valid_number(rgb[0]) || !is_valid_number(rgb[1]) || !is_valid_number(rgb[2]))
		return (free(rgb), ERR_INVALID_RGB);
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	if (color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		err = ERR_INVALID_RGB;
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
	return (err);
}

t_error	handle_colors(char *line, char *token, t_game *map)
{
	int		i;
	int		start;
	int		len;
	char	*value;
	t_error	err;

	i = 0;
	err = SUCCESS;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0')
		return (ERR_INVALID_FORMAT);
	start = i;
	len = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
	{
		i++;
		len++;
	}
	value = ft_substr(line, start, len);
	if (!value)
		return (ERR_MALLOC);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (free(value), ERR_INVALID_FORMAT);
		i++;
	}
	if (ft_strcmp(token, "F") == 0)
	{
		if (map->textures->floor.r != -1)
			return (free(value), ERR_DUP_COLOR);
		err = parse_rgb(value, &map->textures->floor);
	}
	else if (ft_strcmp(token, "C") == 0)
	{
		if (map->textures->ceiling.r != -1)
			return (free(value), ERR_DUP_COLOR);
		err = parse_rgb(value, &map->textures->ceiling);
	}
	return (free(value), err);
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
		err = handle_textures(line + i, token, map->textures);
	else
	{
		return (free(token), ERR_INVALID_TOKEN);
	}
	return (free(token), err);
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
		if (line_temp[0] != '\n')
		{
			trimmed_line = ft_strtrim(line_temp, "\n");
			printf("RAW LINE: [%s]\n", trimmed_line);
			err = parse_texture(trimmed_line, map, 0);
			if (err != SUCCESS)
			{
				close(map_fd);
				free(trimmed_line);
				free(line_temp);
				return ;
			}
			free(trimmed_line);
		}
		free(line_temp);
	}
	close(map_fd);
}

/*int	check_retangular(char **map, int expected_cols)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != expected_cols)
			return (0);
		i++;
	}
	return (1);
}*/

/*void	start_map(void, t_game *map)
{
	init_map(map->map_path);
	map->->map_alloc = true;
	if (check_retangular(map->->full, map->colums) == 0)
		error_msg("Extra wall recognized\n");
	check_columns(map->);
	check_rows(map->);
	get_player(*map->, &objs()->player);
	count_map(map->);
	verify_parameters(map->);
	fill_flood();
	if (map->full_map[(int)objs()->player.pos_y][(int)objs()->player.pos_x] \
== 'P')
		mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, \
canvas()->player_right.mlx_img, objs()->player.pos_x * ICON, \
objs()->player.pos_y * ICON);
}
*/