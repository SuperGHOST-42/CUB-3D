/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:15:48 by figomes           #+#    #+#             */
/*   Updated: 2026/06/25 14:47:26 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/cub3d.h"

static char	*extract_texture_value(char *line, int *i)
{
	int	start;
	int	len;

	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	if (line[*i] == '\0' || line[*i] == '\n')
		return (NULL);
	start = *i;
	len = 0;
	while (line[*i] && line[*i] != ' ' && line[*i] != '\t'
		&& line[*i] != '\n')
	{
		(*i)++;
		len++;
	}
	return (ft_substr(line, start, len));
}

static int	check_texture_trailing(char *line, int i)
{
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static t_error	set_texture(char *token, t_textures *t, char *str, t_game *g)
{
	if (ft_strcmp(token, "NO") == 0 && !t->north_path)
		return (t->north_path = str, g->alloc_tex++, SUCCESS);
	if (ft_strcmp(token, "SO") == 0 && !t->south_path)
		return (t->south_path = str, g->alloc_tex++, SUCCESS);
	if (ft_strcmp(token, "WE") == 0 && !t->west_path)
		return (t->west_path = str, g->alloc_tex++, SUCCESS);
	if (ft_strcmp(token, "EA") == 0 && !t->east_path)
		return (t->east_path = str, g->alloc_tex++, SUCCESS);
	return (free(str), ERR_DUP_TEXTURE);
}

t_error	handle_textures(char *line, char *token,
		t_textures *textures, t_game *game)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	str = extract_texture_value(line, &i);
	if (!str)
		return (ERR_MISSING_VALUE);
	if (!check_texture_trailing(line, i))
		return (free(str), ERR_INVALID_FORMAT);
	return (set_texture(token, textures, str, game));
}
