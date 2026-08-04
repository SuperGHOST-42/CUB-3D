# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

NAME		= cub3D

CC			= cc
CFLAGS		= -std=gnu17 -Wall -Wextra -Werror

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes

LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= includes/minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRC			= main.c \
			  parse/check_map.c \
			  parse/check_map2.c \
			  parse/free.c \
			  parse/handle_colors.c \
			  parse/handle_textures.c \
			  parse/handle_textures2.c \
			  parse/init_game.c \
			  parse/map_init.c \
			  parse/validate_textures.c	\
			  player_init.c \
			  moves.c \
			  raycast.c \
			  render.c \
			  texture.c \
			  input.c \
			  mlx_cleanup.c \
			  mlx_init.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# **************************************************************************** #
#                                RULES                                         #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(MAKE) -C $(MLX_DIR) CFLAGS="-O3 -std=gnu17 -I.."
	$(CC) $(CFLAGS) $(OBJS) \
	-I$(INC_DIR) \
	-L$(LIBFT_DIR) -lft \
	$(MLX_FLAGS) \
	-o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) \
	-I$(INC_DIR) \
	-I$(LIBFT_DIR) \
	-I$(MLX_DIR) \
	-c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) CFLAGS="-O3 -std=gnu17 -I.." clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# **************************************************************************** #
#                                PHONY                                         #
# **************************************************************************** #

.PHONY: all clean fclean re
