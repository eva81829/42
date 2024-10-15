# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex
SRC = main.c arg.c pipex.c fd.c execute.c exe.c path.c free.c
SRC_DIR = sources/
SRC_OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

BONUS_NAME = pipex
BONUS = main_bonus.c arg.c pipex.c fd.c execute.c exe.c path.c free.c
BONUS_DIR = sources/
BONUS_OBJ = $(addprefix $(BONUS_DIR), $(BONUS:.c=.o))

GET = get_next_line.c get_next_line_utils.c
GET_DIR = get_next_line/
GET_OBJ = $(addprefix $(GET_DIR), $(GET:.c=.o))

INC_DIR = includes/
INCLUDES = -I $(INC_DIR)

LIBFT_DIR = Libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# Pipex targets
all: lib $(NAME)
$(NAME): $(SRC_OBJ) $(GET_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(SRC_OBJ) $(GET_OBJ) -o $@
bonus: lib $(BONUS_NAME) 
$(BONUS_NAME): $(BONUS_OBJ) $(GET_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $(BONUS_OBJ) $(GET_OBJ) -o $@
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
.PHONY: all bonus clean fclean re lib lclean lfclean