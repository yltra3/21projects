NAME		= megaphone
COMPILER	= clang++
FLAGS		= -Wall -Wextra -Werror
SRC			= megaphone.cpp test.cpp
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	./megaphone "shhhhh... I think the students are asleep..."
	@echo
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
	@echo
	./megaphone