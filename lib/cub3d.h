#ifndef CUB3D
#define CUB3D

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/time.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_map
{
	char		**full;
	char		*map_name;
	int			players;
	t_player	player;
	t_bool		map_alloc;
}	t_map;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
}	t_win;

typedef struct s_player
{
	int		start_x;
	int		start_y;
	double	pos_x;
	double	pos_y;
	char	init_direction; //N/S/E/W
}	t_player;


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