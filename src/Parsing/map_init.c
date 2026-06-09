/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:24:26 by figomes           #+#    #+#             */
/*   Updated: 2026/06/08 15:38:01 by figomes          ###   ########.fr       */
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

void	init_map(char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;
	char	**x;
	char	**y;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		error_msg("The Map couldn't be opened\n");
	map_temp = ft_strdup("");
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_str_doublepointer(&map_temp, line_temp);
		free(line_temp);
	}
	close(map_fd);
	check_for_empty_line(map_temp);
	x = ft_split(map_temp, '\n');
	y = ft_split(map_temp, '\n');
	map()->full = x;
	map()->test = y;
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

void	start_map(void)
{
	init_map(map()->map_path);
	map()->map_alloc = true;
	if (check_retangular(map()->full, map()->colums) == 0)
		error_msg("Extra wall recognized\n");
	check_columns(map());
	check_rows(map());
	get_player(*map(), &objs()->player);
	count_map(map());
	verify_parameters(map());
	fill_flood();
	if (map()->full[(int)objs()->player.pos_y][(int)objs()->player.pos_x] \
== 'P')
		mlx_put_image_to_window(win()->mlx_ptr, win()->win_ptr, \
canvas()->player_right.mlx_img, objs()->player.pos_x * ICON, \
objs()->player.pos_y * ICON);
}
