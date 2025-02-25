CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Ilibs/Libft -Ilibs/mlx42/include
LDFLAGS = -Llibs/Libft -Llibs/mlx42/build
RM = rm -f

NAME = so_long
SRC_FILES = src/main.c src/read_map.c src/clean_map.c src/validate_map.c src/find_a_path.c src/load_textures.c src/move_player.c src/initialize_map.c src/collect_item.c
SRC_OBJ = $(SRC_FILES:.c=.o)

LIBFT_DIR = libs/Libft
MLX_DIR = libs/mlx42

LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/build/libmlx42.a

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
LIBS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else
LIBS = -lft -lmlx42 -lglfw -ldl -lm -pthread
endif

all: $(LIBFT_LIB) $(MLX_LIB) $(NAME)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build -j4

$(NAME): $(SRC_OBJ) $(LIBFT_LIB) $(MLX_LIB)
	@$(CC) $(CFLAGS)  $(LDFLAGS) $(SRC_OBJ) $(LIBS) -o $(NAME)

clean:
	@$(RM) $(SRC_OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX_DIR)/build
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re