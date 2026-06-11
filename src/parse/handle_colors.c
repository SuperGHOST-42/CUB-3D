/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:14:55 by figomes           #+#    #+#             */
/*   Updated: 2026/06/25 14:43:45 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_number(char *str)
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

t_error	parse_rgb(char *value, t_colors *color, t_game *game)
{
	char	**rgb;
	int		i;

	rgb = ft_split(value, ',');
	if (!rgb)
		return (ERR_MALLOC);
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3 || !is_valid_number(rgb[0])
		|| !is_valid_number(rgb[1]) || !is_valid_number(rgb[2]))
		return (free_rgb(rgb), ERR_INVALID_FORMAT);
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	game->alloc_tex++;
	if (color->r < 0 || color->r > 255
		|| color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		return (free_rgb(rgb), ERR_INVALID_RGB);
	free_rgb(rgb);
	return (SUCCESS);
}

static char	*extract_value(char *line, int *i)
{
	int	start;
	int	len;

	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	if (line[*i] == '\0')
		return (NULL);
	start = *i;
	len = 0;
	while (line[*i] && line[*i] != ' ' && line[*i] != '\t')
	{
		(*i)++;
		len++;
	}
	return (ft_substr(line, start, len));
}

static int	check_trailing(char *line, int i)
{
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

t_error	handle_colors(char *line, char *token, t_game *map)
{
	int		i;
	char	*value;
	t_error	err;

	i = 0;
	err = SUCCESS;
	value = extract_value(line, &i);
	if (!value)
		return (ERR_INVALID_FORMAT);
	if (!check_trailing(line, i))
		return (free(value), ERR_INVALID_FORMAT);
	if (ft_strcmp(token, "F") == 0)
	{
		if (map->textures->floor.r != -1)
			return (free(value), ERR_DUP_COLOR);
		err = parse_rgb(value, &map->textures->floor, map);
	}
	else if (ft_strcmp(token, "C") == 0)
	{
		if (map->textures->ceiling.r != -1)
			return (free(value), ERR_DUP_COLOR);
		err = parse_rgb(value, &map->textures->ceiling, map);
	}
	return (free(value), err);
}
