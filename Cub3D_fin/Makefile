CC = gcc

SRCS := 	src/cub3d.c\
			src/border_checker.c\
			src/calculate.c\
			src/check_struct_flag.c\
			src/file_checker.c\
			src/init_player.c\
			src/initialization.c\
			src/key.c\
			src/key_help.c\
			src/line_color_checker.c\
			src/map_checker.c\
			src/map_parser.c\
			src/mini_map.c\
			src/move.c\
			src/render.c\
			src/render_initialization.c\
			src/symbols_checker.c\
			src/symbol_checker_help.c\
			src/utils.c\
			./get_next_line/get_next_line.c \
            ./get_next_line/get_next_line_utils.c \

NAME	=	cub3D

INCLUDE = -I./ -I./get_next_line

FRAEMWORKS= -framework OpenGL -framework AppKit

HEADER = cub3d.h

LIBS = libft.a libmlx.a

CFLAGS	= -Wall -Wextra -Werror -Ofast -march=native

OBJ		=	$(patsubst %.c, %.o,$(SRCS))

%.o:%.c $(HEADER)
			$(CC) $(CFLAGS) $(INCLUDE) -c -g $< -o $@
all		:	$(NAME)

$(NAME)	: $(OBJ)
	$(MAKE) -C ./libft
	cp libft/libft.a .
	$(MAKE) -C minilibx_macos/ all
	cp minilibx_macos/libmlx.a .
	$(CC) $(CFLAGS) -g -o $(NAME) $(FLAG) $(OBJ) $(FRAEMWORKS) $(LIBS)

clean:
	rm -rf $(OBJ) $(LIBS)
	$(MAKE) -C ./minilibx_macos/ clean
	$(MAKE) -C ./libft clean

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -rf $(NAME)

re:		fclean all

$(NAME)	:	$(OBJ)

