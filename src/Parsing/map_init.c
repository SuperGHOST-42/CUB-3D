/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:24:26 by figomes           #+#    #+#             */
/*   Updated: 2026/06/09 15:50:21 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Library/cub3d.h"

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

void	handle_textures(char *line, char *token, t_textures *textures)
{
	int		i;
	int		start;
	int		len;
	char	*str;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return ; // erro: sem path
	start = i;
	len = 0;
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0' && line[i] != '\n')
	{
		i++;
		len++;
	}
	str = ft_substr(line, start, len);
	if (!str)
		return ; // erro malloc
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '\t')
		{
			free(str);
			return ; // erro: lixo depois do path
		}
		i++;
	}
	if (ft_strcmp(token, "NO") == 0)
		textures->north_path = str;
	else if (ft_strcmp(token, "SO") == 0)
		textures->south_path = str;
	else if (ft_strcmp(token, "WE") == 0)
		textures->west_path = str;
	else if (ft_strcmp(token, "EA") == 0)
		textures->east_path = str;
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

void	parse_rgb(char *value, t_colors *color)
{
	char	**rgb;
	int		i;

	i = 0;

	rgb = ft_split(value, ',');
	if (!rgb)
		return ; // erro malloc

	while (rgb[i])
		i++;

	if (i != 3)
		return ; // erro formato

	if (!is_valid_number(rgb[0]) || !is_valid_number(rgb[1]) || !is_valid_number(rgb[2]))
		return ; // erro

	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);

	// valida range
	if (color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		return ; // erro
		
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
}

void	handle_colors(char *line, char *token, t_game *map)
{
	int		i;
	int		start;
	int		len;
	char	*value;

	i = 0;

	while (line[i] == ' ' || line[i] == '\t')
		i++;

	if (line[i] == '\0')
		return ;

	start = i;
	len = 0;

	while (line[i] && line[i] != ' ' && line[i] != '\t')
	{
		i++;
		len++;
	}

	value = ft_substr(line, start, len);
	if (!value)
		return ;

	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			free(value);
			return ; // erro lixo
		}
		i++;
	}

	if (ft_strcmp(token, "F") == 0)
		parse_rgb(value, &map->floor);
	else if (ft_strcmp(token, "C") == 0)
		parse_rgb(value, &map->ceiling);

	free(value);
}

void	parse_texture(char	*line, t_game *map)
{
	int		i;
	int		j;
	char	*token;
	t_token	*token_type;

	i = 0;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return ;
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0' && line[i] != '\n')
		token[j++] = line[i++];
	token[j] = '\0';
	token_type = check_token_type(token);
	if (token_type == TOKEN_COLOR)
		handle_colors(line, token, map);
	else if (token_type == TOKEN_TEXTURE)
		handle_textures(line, token, map->textures);
	else
		return ; //Definir erro
}

void	init_map(char *argv, t_game *map)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;
	char	**x;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		error_msg("The Map couldn't be opened\n");
	map_temp = ft_strdup("");
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		parse_texture(line_temp, map);
		map_temp = ft_str_doublepointer(&map_temp, line_temp);
		free(line_temp);
	}
	close(map_fd);
	check_for_empty_line(map_temp);
	x = ft_split(map_temp, '\n');
	map->full_map = x;
	free(map_temp);
}

int	check_retangular(char **map, int expected_cols)
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
}

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