#include "../includes/cub.h"

void	init_player(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'N')
			{
				game->player.x = x + 0.5;
				game->player.y = y + 0.5;
				game->player.dir_x = 0;
				game->player.dir_y = -1;
				game->player.fov_x = 0.66;
				game->player.fov_y = 0;
				game->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

char	**dup_map(char **src)
{
	char	**dst;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dst = malloc(sizeof(char *) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		if (!dst[i])
			return (NULL);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}