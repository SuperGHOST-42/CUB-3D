#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/libft.h"
# include "macro.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_error
{
	SUCCESS = 0,
	ERR_MALLOC,
	ERR_INVALID_FORMAT,
	ERR_DUP_TEXTURE,
	ERR_DUP_COLOR,
	ERR_INVALID_TOKEN,
	ERR_INVALID_RGB,
	ERR_MISSING_VALUE,
	ERR_MAP_OPEN_FAIL
}	t_error;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_token
{
	TOKEN_TEXTURE,
	TOKEN_COLOR,
	TOKEN_INVALID
}	t_token;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}	t_colors;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

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

typedef struct s_textures
{
	char		*north_path;
	char		*south_path;
	char		*east_path;
	char		*west_path;
	t_colors	floor;
	t_colors	ceiling;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**full_map;
	t_img		img;
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	t_player	player;
	char		*map_path;
	int			map_height;
	int			players;
	int			map_started;
	t_bool		map_alloc;
	t_textures	*textures;
	int			alloc_tex;
}	t_game;

void	check_command(int argc, char *argv);
void	init_map(char *argv, t_game *map);
void	init_game(t_game *game);
void	error_msg(char *message, t_game *game);
char	*ft_str_doublepointer(char **s1, const char *s2);
void	clean_game(t_game *game);
void	print_error(t_error err, t_game *game);
t_error	validate_config(t_game *map);
t_error	parse_rgb(char *value, t_colors *color, t_game *game);
t_error	handle_colors(char *line, char *token, t_game *map);
t_error	handle_textures(char *line, char *token, t_textures *textures,
			t_game *game);
void	free_rgb(char **rgb);
t_error	parse_texture(char *line, t_game *map, int i);
void	print_textures(t_textures *t);
void	print_colors(char *name, t_colors c);
void	print_map(char **map);
void	print_game(t_game *g);
void	init_player(t_game *game);
char	**dup_map(char **src);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
void	raycast(t_game *game);
void	draw_column(t_game *game, t_ray *ray, int x);
void	init_mlx(t_game *game);
void	init_debug_map(t_game *game);

#endif
