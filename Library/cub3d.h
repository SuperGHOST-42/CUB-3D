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
} t_error;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
} t_player;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}	t_colors;

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
}   t_token;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_textures
{
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
	t_colors	floor;
	t_colors	ceiling;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**full_map;
	char		*map_path;
	int			players;
	//t_player	player;
	t_bool		map_alloc;
	//t_img		img;
	t_textures	*textures;
	int			alloc_tex;
}				t_game;

void	check_command(int argc, char *argv);
void	init_map(char *argv, t_game *map);
void	init_game(t_game *game);
void	error_msg(char *message, t_game *game);
char	*ft_str_doublepointer(char **s1, const char *s2);
void	clean_game(t_game *game);
void	print_error(t_error err, t_game *game);
t_error	validate_config(t_game *map);
t_error	parse_rgb(char *value, t_colors *color, t_game	*game);
t_error	handle_colors(char *line, char *token, t_game *map);
t_error	handle_textures(char *line, char *token, t_textures *textures, t_game *game);

#endif