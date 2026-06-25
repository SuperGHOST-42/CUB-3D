/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:50:06 by figomes           #+#    #+#             */
/*   Updated: 2026/06/25 15:04:58 by figomes          ###   ########.fr       */
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

static char	*extract_token(char *line, int *i)
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

static t_error	dispatch_token(char *token, char *rest, t_game *map)
{
	t_token	type;

	type = check_token_type(token);
	if (type == TOKEN_COLOR)
		return (handle_colors(rest, token, map));
	if (type == TOKEN_TEXTURE)
		return (handle_textures(rest, token, map->textures, map));
	return (ERR_INVALID_TOKEN);
}

t_error	parse_texture(char *line, t_game *map, int i)
{
	char	*token;
	t_error	err;

	token = extract_token(line, &i);
	if (!token)
		return (SUCCESS);
	err = dispatch_token(token, line + i, map);
	free(token);
	return (err);
}
