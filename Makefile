CC=cc
CC_FLAGS=-Wall -Wextra -Werror
LIBFT_FLAGS=-Llib/libft -lft
MLX_FLAGS=-Llib/minilibx-linux -lmlx_Linux -lX11 -lXext
NAME=libsolong.a
EXEC_NAME=so_long
INC_DIR=include
INC_DIR_BONUS=include_bonus
SRC_DIR=src
LIB_DIR=lib
SRC_FILES=clean_utils.c char_utils.c gameplay_utils.c map_data_utils.c map_iter_utils.c mlx_draw_utils.c mlx_utils.c \
	  size_utils.c so_long.c st_map_utils.c validation_utils.c
BONUS_SRC_FILES=clean_utils.c char_utils.c gameplay_utils.c map_data_utils.c map_iter_utils.c mlx_draw_utils_bonus.c mlx_utils.c \
	  size_utils.c so_long.c st_map_utils.c validation_utils.c
LIBFT_DIR=$(LIB_DIR)/libft
LIBFT=$(LIBFT_DIR)/libft.a
MINILIBX_DIR=$(LIB_DIR)/minilibx-linux
MINILIBX=$(MINILIBX_DIR)/libmlx_Linux.a
SRCS=$(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRCS=$(addprefix $(SRC_DIR)/, $(BONUS_SRC_FILES))
OBJS=$(SRCS:.c=.o)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)

all: $(NAME) $(LIBFT) $(MINILIBX)
	$(CC) $(CC_FLAGS) -o $(EXEC_NAME) -L. -lsolong $(LIBFT_FLAGS) $(MLX_FLAGS) -I$(INC_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	ar rcs $@ $(OBJS) $(LIBFT) $(MINILIBX)

bonus: clean_m $(BONUS_OBJS) $(LIBFT) $(MINILIBX)
	ar rcs $(NAME) $(BONUS_OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CC_FLAGS) -o $(EXEC_NAME) -L. -lsolong $(LIBFT_FLAGS) $(MLX_FLAGS) -I$(INC_DIR_BONUS)

.c.o:
	$(CC) $(CC_FLAGS) -c $< -o $@

_bonus.c_bonus.o:
	$(CC) $(CC_FLAGS) -c $< -o $@

clean_m:
	rm -f $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS) $(MINILIBX)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(EXEC_NAME)

re: fclean all

.PHONY: all clean fclean re
