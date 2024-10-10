# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRC = main.c check_input.c convert_input.c stack.c \
		instruction.c small_sort.c radix_sort.c 
SRC_OBJ = $(SRC:.c=.o)

LIBFT_DIR = Libft/
LIBFT_OBJ = $(addprefix $(LIBFT_DIR), libft.a)

# Push swap targets
all: $(NAME)
# create "./push_swap", it will only relink when $(LIBFT_OBJ) $(SRC_OBJ) change
$(NAME): $(LIBFT_OBJ) $(SRC_OBJ)
	$(CC) $(CFLAGS) $(LIBFT_OBJ) $(SRC_OBJ) -o $@
# create "Libft/libft.a"
$(LIBFT_OBJ):
	make bonus -C $(LIBFT_DIR)
# using SRC.c to create the SRC.o like "main.o", "check_input.o"...
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I.
clean:
	rm -f $(SRC_OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

# Libft targets
lib: $(LIBFT_OBJ)
lclean:
	make clean -C $(LIBFT_DIR)
lfclean:
	make fclean -C $(LIBFT_DIR)

# Declare targets as "phony"
.PHONY: all clean fclean re lib lclean lfclean