NAME		= phonebook
COMPILER	= clang++
FLAGS		= -Wall -Wextra -Werror
SRC			= phonebook.cpp scrappy.cpp main.cpp
INC			= phonebook.h scrappy.h
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
