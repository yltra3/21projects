SRCS = srcs/draw.c srcs/scene_check.c srcs/color_utils.c srcs/ft_split.c\
srcs/intersect.c srcs/main.c srcs/parser.c srcs/parser_helper.c srcs/ray.c\
srcs/sphere.c srcs/third.c srcs/cr_buf.c srcs/color.c srcs/cylinder.c\
srcs/gnl.c srcs/parsein.c srcs/third_helper.c\
srcs/plane.c srcs/shaders.c srcs/square.c srcs/checkin.c\
srcs/color_helper.c srcs/ft_atoi_plus.c srcs/gnl_helper.c srcs/list_utils.c\
srcs/mini_rt.c srcs/objects_parse.c srcs/equation.c srcs/spec.c\
srcs/triangle.c srcs/cylinder_helper.c
OBJS = $(SRCS:.c=.o)
NAME = miniRT

CFLAGS = -Wall -Wextra -Werror

.PHONY: 	clean fclean all re bonus

all:		$(NAME)

.c.o:
			gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			make -C ./MinilibX
			gcc -o $(NAME) $(OBJS) $(CFLAGS) -lmlx -L./MinilibX -framework OpenGL -framework AppKit

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re:			fclean all