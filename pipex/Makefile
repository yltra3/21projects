NAME		= 	pipex
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	mandatory/files.c \
				mandatory/fork.c \
				mandatory/free.c \
				mandatory/pipex.c\
				utils/ft_strjoin.c\
				utils/ft_strncmp.c\
				utils/ft_strlen.c\
				utils/ft_split.c\

BSRCS		=	bonus/files_bonus.c\
				bonus/fork_bonus.c\
				bonus/free_bonus.c\
				bonus/pipex_bonus.c\
				utils/ft_strjoin.c\
				utils/ft_strncmp.c\
				utils/ft_strlen.c\
				utils/ft_split.c\
				GNL/get_next_line.c\
				GNL/get_next_line_utils.c\

OBJ			=	$(SRCS:%.c=%.o)

BOBJ		=	$(BSRCS:%.c=%.o)

INCLUDES	=	mandatory/pipex.h

BINCLUDES	=	bonus/pipex_bonus.h

.o: .c
				$(CC) $(CFLAGS)	$< -o $@ 

all: 			$(OBJ) mandatory/pipex.h
				@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	 			@echo "Make done"

		
		
bonus: 			$(BOBJ) bonus/pipex_bonus.h
				$(CC) $(CFLAGS) $(BOBJ) -o $(NAME)
				@echo "Make bonus done"

			

clean:
	@rm -f $(OBJ) $(BOBJ)
	@echo "Make clean done"

fclean: clean
	@rm -f $(NAME) $(BNAME)
	@echo "Make fclean done"

re: fclean all

norm:
	norminette 
 
.PHONY: all re clean fclean norm bonus