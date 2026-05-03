/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:31:14 by arpereir          #+#    #+#             */
/*   Updated: 2026/05/03 23:48:11 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "macro.h"

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	fov_x;
	double	fov_y;
} t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_player	player;
} t_game;

//parse
void	init_player(t_game *game);
char	**dup_map(char **src);

//moves
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

#endif