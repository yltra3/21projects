SRCS	= main.c ft_controllers.c ft_linku_starto.c ft_parse_map.c\
ft_solong_hooks.c

BONUS	= main_bonus.c ft_controllers.c ft_linku_starto.c ft_parse_map.c\
ft_solong_hooks.c

OBJS		= $(SRCS:.c=.o)

BONUS_OBJS	= $(BONUS:.c=.o)

name		= so_long

b_name		= so_long_bonus

header		= ./so_long.h

cflags		= -Wall -Wextra -Werror

links		= -lmlx -lm -L ./minilibx_opengl -framework OpenGL -framework Appkit

lib			= ./libft/libft.a

CC			= gcc

RM 			= rm -f

.PHONY: all clean fclean re bonus norm libft minilibx

all:		$(name)

minilibx:	$(MAKE) -C ./minilibx_opengl 2> /dev/null

%.o:%.c		$(header)
			$(CC) $(cflags) -c $< -o $(<:.c=.o)

libft:		$(MAKE) -C ./libft/


$(name):	$(OBJS) $(header)
			$(MAKE) -C ./libft/
			${MAKE} -C ./minilibx_opengl 2> /dev/null
			$(CC) $(cflags) -o $(name) -I $(header) $(OBJS) $(lib) $(links)
	@echo "compiled"

bonus:		$(b_name)

$(b_name):	$(BONUS_OBJS) $(header)
			$(MAKE) -C ./libft/
			${MAKE} -C ./minilibx_opengl 2> /dev/null
			$(CC) $(cflags) -o $(b_name) -I $(header) $(BONUS_OBJS) $(lib) $(links)
	@echo "compiled bonus"

norm:		
	@norminette ./
	@norminette ./libft/
	@echo "norm check done"

clean:		
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@make clean -C ./libft/
	@make -C ./minilibx_opengl clean
	@echo "clean done"

fclean:		
	@$(RM) ${OBJS} ${BONUS_OBJS} ${name} ${b_name}
	@make fclean -C ./libft/
	@make -C ./minilibx_opengl clean
	@echo "fclean done"

re:			fclean all