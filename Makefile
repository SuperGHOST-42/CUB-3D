NAME       = cub3d
CC         = cc

CFLAGS     = -Wall -Wextra -Werror -g

SRC_DIR    = ./src
OBJ_DIR    = ./obj

LIBFT_DIR  = ./Libft
LIBFT      = -L$(LIBFT_DIR) -lft

MLX_DIR    = ./minilibx-linux
MLX_FLAGS  = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

INCLUDES   = -I./include -I$(LIBFT_DIR) -I$(MLX_DIR)

SRCS =  src/main.c 		\
        src/init_game.c \
		src/free.c		\
        src/map_init.c

OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re