# Variables
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook
SRC = main.cpp add.cpp search.cpp PhoneBook.cpp Contact.cpp
# Performs a transformation where .cpp is replaced with .o
OBJ = $(SRC:.cpp=.o)

# PhoneBook targets
all: $(NAME)

# Rule to link object files and create the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# Rule to compile .cpp files to .o object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Clean up object files and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all