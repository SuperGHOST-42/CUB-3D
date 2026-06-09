# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes

LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= includes/minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRC			= main.c \
			  parse.c \
			  moves.c \
			  raycast.c \
			  render.c \
			  mlx_init.c \
			  init_game.c \
			  map_init.c \
			  free.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# **************************************************************************** #
#                                RULES                                         #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) \
	-I$(INC_DIR) \
	-L$(LIBFT_DIR) -lft \
	$(MLX_FLAGS) \
	-o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) \
	-I$(INC_DIR) \
	-I$(LIBFT_DIR) \
	-I$(MLX_DIR) \
	-c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# **************************************************************************** #
#                                PHONY                                         #
# **************************************************************************** #

.PHONY: all clean fclean re
