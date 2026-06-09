/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:31:14 by arpereir          #+#    #+#             */
/*   Updated: 2026/05/15 18:04:39 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "macro.h"
# include "minilibx-linux/mlx.h"

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
} t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
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

//raycast
void	raycast(t_game *game);

//render
void	draw_column(t_game *game, t_ray *ray, int x);

//mlx
void	init_mlx(t_game *game);

#endif