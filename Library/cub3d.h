#ifndef CUB3D
#define CUB3D

//# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}	t_colors;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_token
{
    TOKEN_TEXTURE,
    TOKEN_COLOR,
    TOKEN_INVALID
}   t_token;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**full_map;
	char		*map_path;
	int			players;
	t_player	player;
	t_bool		map_alloc;
	t_img		img;
	t_textures	*textures;
	t_colors	floor;
	t_colors	ceiling;
}				t_game;

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

typedef struct s_textures
{
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
	char	*floor_colors;
	char	*ceiling_colors;
}	t_textures;


void	check_command(int argc, char *argv);

#endif