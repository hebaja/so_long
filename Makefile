CC=cc
CC_FLAGS= -Wall -Wextra -Werror
MLX_FLAGS= -Lminilibx-linux -lmlx -lX11 -lXext 
NAME=libsolong.a
INC_DIR=include
SRC_DIR=src
SRC_FILES=alloc_mem_utils.c char_utils.c gameplay_utils.c map_data_utils.c map_iter_utils.c mlx_draw_utils.c mlx_utils.c \
	  so_long.c st_map_utils.c validation_utils.c
BONUS_SRC_FILES=mlx_draw_utils_bonus.c
LIBFT=lib/libft/libft.a
MINILIBX=lib/minilibx-linux/libmlx_Linux.a
SRCS=$(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRCS=$(addprefix $(SRC_DIR)/, $(BONUS_SRC_FILES))
OBJS=$(SRCS:.c=.o)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)

all: $(NAME) $(LIBFT)
	cc $(CC_FLAGS) $(MLX_FLAGS) -Llib/libmlx_Linux -lmlx_linux -Llib/libft/ -lft --L. -lsolon go so_long

$(LIBFT):
	make -C libft/

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $@ $(OBJS) $(LIBFT)

bonus: clean_a $(BONUS_OBJS) $(LIBFT)
	ar rcs $(NAME) $(BONUS_OBJS) $(LIBFT)
	cc $(CC_FLAGS) -L. -lpipex -Llibft/ -lft -o pipex

.c.o:
	$(CC) $(CC_FLAGS) -c $< -o $@

_bonus.c_bonus.o:
	$(CC) $(CC_FLAGS) -c $< -o $@

clean_a:
	rm -f $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	rm -f pipex

re: fclean all

.PHONY: all clean fclean re
