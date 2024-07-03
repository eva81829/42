# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L"MLX42/build" -lmlx42 -L"/Users/fwu/.brew/opt/glfw/lib/" -lglfw

NAME = so_long
SRC = main.c 
SRC_DIR = sources/
SRC_OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

INC_DIR = includes/
INCLUDES = -I $(INC_DIR)

LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# So long targets
all: lib $(NAME)
$(NAME): $(SRC_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(SRC_OBJ) $(MLXFLAGS) -o $@
clean:
	rm -f $(SRC_OBJ) $(BONUS_OBJ) $(GET_OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

# Libft targets
lib:
	make -C $(LIBFT_DIR)
lclean:
	make clean -C $(LIBFT_DIR)
lfclean:
	make fclean -C $(LIBFT_DIR)

# Declare targets as "phony"
.PHONY: all clean fclean re lib lclean lfclean