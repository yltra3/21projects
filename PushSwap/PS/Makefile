NAME		= 	push_swap
BNAME		=	checker
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	push_swap.c \
				error_exit.c \
				parser.c \
				indexes.c\
				three_arg.c\
				pushes.c\
				rarbrr.c\
				rrarrbrrr.c\
				sasbss.c\
				algorithm.c\
				search.c\
				steps.c\
				swap_st.c\
				liba/ft_atoi.c\
				liba/ft_lstclear.c\
				liba/ft_lst_last.c\
				liba/ft_lstadd_back.c\
				liba/ft_lst_free.c\
				liba/ft_lstsize.c\
				liba/ft_lst_new.c\
				liba/ft_split.c\
				liba/ft_strchr.c\
				liba/ft_strlen.c\

BSRCS		=	bonus/indexes.c\
				bonus/pushes.c\
				bonus/ft_lstadd_back.c\
				bonus/rarbrr.c\
				bonus/error_exit.c\
				bonus/ft_lstclear.c\
				bonus/rrarrbrrr.c\
				bonus/ft_atoi.c\
				bonus/ft_lst_free.c\
				bonus/sasbss.c\
				bonus/ft_split.c\
				bonus/ft_lst_last.c\
				bonus/op_st.c\
				bonus/ft_strchr.c\
				bonus/ft_lst_new.c\
				bonus/parser.c\
				bonus/ft_strlen.c\
				bonus/ft_lstsize.c\
				bonus/get_next_line.c\
				bonus/main.c

OBJ			=	$(SRCS:%.c=%.o)

BOBJ		=	$(BSRCS:%.c=%.o)

INCLUDES	=	push_swap.h

BINCLUDES	=	bonus/checker.h

.o: .c
	$(CC) $(CFLAGS)	$< -o $@ 

all: $(NAME)
	 @echo "Make done"

$(NAME): $(OBJ) push_swap.h
		 @$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
		
bonus: $(BNAME)
	@echo "Make bonus done"

$(BNAME): $(BOBJ) bonus/checker.h
			$(CC) $(CFLAGS) $(BOBJ) -o $(BNAME)

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