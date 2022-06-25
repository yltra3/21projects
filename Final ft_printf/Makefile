NAME	= libftprintf.a

CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g3

DIR_S = srcs

DIR_O = obj

SOURCES =  ft_printf.c ft_print_char.c ft_print_string.c\
ft_strlen_pr.c ft_isdigit_pr.c ft_putstr_pr.c ft_print_int.c ft_putnbr_pr.c ft_calloc_pr.c\
ft_bzero_pr.c ft_print_smhex.c ft_print_bghex.c ft_print_uns.c ft_print_pointer.c\
ft_print_percent.c ft_hex_helper.c ft_print_string_helper.c ft_print_int_helper.c\
ft_print_int_helper2.c ft_uns_helper.c

OBJS		= ${SRCS:.c=.o}

HEADER = includes

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all:$(NAME)

.c.o:
		${CC} ${CFLAGS} -c -o ${<:.c=.o} ${<}

$(NAME): ${OBJS}
	@ar rcs $(NAME) $(OBJS)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: all
rebonus: fclean bonus
debug: CFLAGS += -g3
debug: all

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: all

.PHONY: debug re fclean all bonus rebonus