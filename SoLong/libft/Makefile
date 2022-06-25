NAME	= libft.a

CC		= gcc
FLAGS	= -Wall -Wextra -Werror -03

SRCS	=  ft_atoi.c  ft_bzero.c  ft_calloc.c  ft_isalnum.c\
ft_isalnum.c  ft_isalpha.c  ft_isascii.c  ft_isdigit.c\
 ft_isprint.c  ft_memchr.c  ft_memcmp.c  ft_memcpy.c  ft_memmove.c\
 ft_memset.c  ft_putnbr.c  ft_putstr.c  ft_strchr.c  ft_strdup.c\
 ft_strlcat.c ft_strlcpy.c ft_strlen.c  ft_strncmp.c  ft_strnstr.c\
 ft_strrchr.c ft_tolower.c ft_toupper.c  ft_itoa.c\
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_putstr_fd.c ft_split.c ft_striteri.c ft_strjoin.c\
ft_strmapi.c ft_strtrim.c ft_substr.c ft_lstadd_back.c\
ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c\
ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\
utils.c ft_chars_count.c get_next_line.c get_next_line_helper.c

OBJS		= ${SRCS:.c=.o}

RM = rm -f

all:$(NAME)

.c.o:
		${CC} ${CFLAGS} -c -o ${<:.c=.o} ${<}

$(NAME): ${OBJS}
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: all

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: all

.PHONY: debug re fclean all