CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c ft_utils.c ft_printf_c.c ft_printf_d.c ft_printf_i.c ft_printf_lx.c ft_printf_p.c ft_printf_s.c ft_printf_u.c ft_printf_ux.c
LIBFT_SRC = libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_strlen.c \
	libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c \
	libft/ft_memset.c libft/ft_bzero.c libft/ft_memchr.c libft/ft_memcpy.c libft/ft_memcmp.c libft/ft_memmove.c \
	libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_atoi.c libft/ft_strnstr.c libft/ft_strdup.c libft/ft_calloc.c \
	libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c \
	libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

all: $(NAME)
# "all" is a target

# Rule to build the executable
$(NAME): $(OBJ) $(LIBFT_OBJ)
	ar rcs $@ $^
# "$(OBJ)" is a dependency, which need to exist before the commands for the target are run
# dependency MUST be a target defined in other line
# "ar rcs $@ $^" is a command
# "$@" is an automatic variable that represents the target name, here is $(NAME)
# "$^" is an automatic variable that represents all the dependencies separated by spaces, here is $(OBJ)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I.
# "$<" is an automatic variable that represents the first dependency, here is %.c
# "-I." means include the current directory for header file search

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

test:
	$(CC) $(CFLAGS) -o main.o -c main.c -I.
	$(CC) $(CFLAGS) main.c libftprintf.a
tclean: fclean
	rm -f main.o