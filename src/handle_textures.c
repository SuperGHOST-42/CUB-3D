/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:15:48 by figomes           #+#    #+#             */
/*   Updated: 2026/06/16 14:26:32 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/cub3d.h"

t_error	handle_textures(char *line, char *token, t_textures *textures, t_game *game)
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
		game->alloc_tex++;
	}
	else if (ft_strcmp(token, "SO") == 0)
	{
		if (textures->south_path != NULL)
			return (free(str), ERR_DUP_TEXTURE);
		textures->south_path = str;
		game->alloc_tex++;
	}
	else if (ft_strcmp(token, "WE") == 0)
	{
		if (textures->west_path != NULL)
			return (free(str), ERR_DUP_TEXTURE);
		textures->west_path = str;
		game->alloc_tex++;
	}
	else if (ft_strcmp(token, "EA") == 0)
	{
		if (textures->east_path != NULL)
			return (free(str), ERR_DUP_TEXTURE);
		textures->east_path = str;
		game->alloc_tex++;
	}
	return (SUCCESS);
}
