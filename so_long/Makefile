# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX42_DIR = MLX42/
MLX42_BUILD_DIR = $(MLX42_DIR)build
USER = $(shell whoami)
MLXFLAGS = -L"$(MLX42_BUILD_DIR)" -lmlx42 -L"/Users/$(USER)/.brew/opt/glfw/lib/" -lglfw

NAME = so_long
SRC = main.c map_create.c map_initialize.c map_check.c map_content_check.c \
		path_find.c union_elements.c union_find.c \
		scene_create.c bg_create.c character_create.c mlx_handler.c player_movement.c \
		error.c
SRC_DIR = sources/
SRC_OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

GET = get_next_line.c get_next_line_utils.c
GET_DIR = get_next_line/
GET_OBJ = $(addprefix $(GET_DIR), $(GET:.c=.o))

INC_DIR = includes/
INCLUDES = -I $(INC_DIR)

LIBFT_DIR = Libft/
LIBFT_OBJ = $(addprefix $(LIBFT_DIR), libft.a)

# So long targets
all: $(NAME)
$(NAME): $(LIBFT_OBJ) $(GET_OBJ) $(SRC_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT_OBJ) $(GET_OBJ) $(SRC_OBJ) $(MLXFLAGS) -o $@
# create "Libft/libft.a"
$(LIBFT_OBJ):
	make bonus -C $(LIBFT_DIR)
# using SRC.c to create the SRC.o like "main.o", "check_input.o"...
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I.
clean:
	rm -f $(GET_OBJ) $(SRC_OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

# MLX targets
# decompress mlx42.tgz and build
mlx:
	tar -xvf mlx42.tgz
	cd $(MLX42_DIR) && cmake -B build
	cd $(MLX42_DIR) && cmake --build build -j4

# Libft targets
lib: $(LIBFT_OBJ)
lclean:
	make clean -C $(LIBFT_DIR)
lfclean:
	make fclean -C $(LIBFT_DIR)

# Declare targets as "phony"
.PHONY: all clean fclean re lib lclean lfclean