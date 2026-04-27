NAME = libft.a

PREP_PRINTF_ERROR = ft_printf_error
PRINTF = ft_add_error.c ft_printf_error.c ft_putchar_error.c ft_putnbr_error.c \
		ft_putnbr_hexa_error.c ft_putstr_error.c
SRC_PRINTF = $(addprefix $(PREP_PRINTF_ERROR)/, $(PRINTF))

SRCS = ft_memset.c				\
		ft_strnstr.c			\
		ft_memcmp.c				\
		ft_bzero.c				\
        ft_atoi.c				\
		ft_memchr.c				\
		ft_memmove.c			\
		ft_memcpy.c				\
        ft_strdup.c				\
		ft_strlen.c				\
		ft_isalpha.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_calloc.c				\
		ft_strncmp.c			\
		ft_strlcat.c			\
		ft_substr.c				\
		ft_strjoin.c			\
		ft_strlcpy.c			\
		ft_itoa.c				\
		ft_split.c				\
		ft_strmapi.c			\
		ft_striteri.c			\
		ft_strtrim.c			\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_atoll.c				\
		ft_putchar_count.c		\
		ft_putnbr_base.c 		\
		ft_putnbr_u.c	 		\
		ft_putnbr_hex.c	 		\
		ft_strlen_count.c		\
		ft_void.c		 		\
		ft_putstr.c				\
		ft_printf.c				\
		get_next_line_utils.c 	\
		get_next_line.c			\
		ft_free_double_pointer.c \
		ft_strcmp.c				\
		$(SRC_PRINTF)

BONUS = ft_lstnew.c				\
		ft_lstadd_front.c		\
		ft_lstsize.c			\
		ft_lstlast.c			\
		ft_lstclear.c			\
		ft_lstdelone.c			\
		ft_lstadd_back.c		\
		ft_lstiter.c			\
		ft_lstmap.c

INCLUDE = libft.h

OBJ = $(SRCS:.c=.o)

BONUS_0 = $(BONUS:.c=.o)

CC = cc

CFLAGS = -Wall    \
         -Wextra  \
         -Werror  \


all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		@ar -rcs $(NAME) $(OBJ)

bonus: $(BONUS) $(BONUS_0)
		@ar -rcs $(NAME) $(BONUS_0)

%.o: %.c $(INCLUDE)
		@$(CC) $(CFLAGS) -c $< -o $@

clean: 
		@rm -rf $(OBJ) $(BONUS_0)

fclean:	
		@rm -rf $(OBJ) $(NAME) $(BONUS_0)

rebonus: fclean bonus

re: fclean all

.PHONY: all clean fclean re rebonus