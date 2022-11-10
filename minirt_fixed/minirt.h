/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 17:37:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* LIBS*/

# include "MinilibX/sierra/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/errno.h>

/* DEFINES */

# define GL_SILENCE_DEPRECATION
# define IMG_HEIGHT 1000
# define IMG_WIDTH 1000
# define FOV 90
# define PIXEL_DATA_OFFSET 54
# define HEADER_SIZE 40
# define PLANES 1
# define BITS_PER_PIXEL 24
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

/* STRUCTS */

typedef struct s_matrix
{
	double	d[4][4];
}				t_matrix;

typedef struct s_memory
{
	char	*str;
	int		position;
	int		length;
	int		last_received;
	int		fd;
}				t_memory;

typedef struct s_qparams
{
	double	a;
	double	b;
	double	c;
}				t_qparams;

typedef struct s_pixel{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
}				t_pixel;

typedef union u_int_color
{
	int				integer;
	unsigned char	comps[4];
}				t_int_color;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}				t_color;

typedef struct s_color2
{
	float	red;
	float	green;
	float	blue;
}				t_color2;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_third
{
	double	x;
	double	y;
	double	z;
}				t_third;

typedef struct s_cylinder
{
	t_third	p;
	t_third	normal;
	double	radius;
	double	height;
}				t_cylinder;

typedef struct s_square
{
	t_third	center;
	t_third	normal;
	double	length;
}				t_square;

typedef struct s_camera
{
	t_third	origin;
	t_third	direction;
	int		fov;
}				t_camera;

typedef struct s_scene
{
	t_list		*objects;
	t_list		*lights;
	int			width;
	int			height;
	double		ambient_intensity;
	t_color2	ambient_color;
	t_list		*cameras;
	int			selected_camera;
}				t_scene;

typedef enum e_object_type
{
	SPHERE,
	CUBE,
	PLANE,
	LIGHT,
	TRIANGLE,
	SQUARE,
	CYLINDER,
}				t_otype;

typedef struct s_object
{
	t_otype		type;
	void		*ptr;
	t_color2	color;
	double		albedo;

}				t_object;

typedef struct s_light
{
	t_third		p0;
	double		intensity;
	t_color2	color;
}				t_light;

typedef struct s_plane
{
	t_third	p0;
	t_third	normal;
}				t_plane;

typedef struct s_triangle
{
	t_third	a;
	t_third	b;
	t_third	c;

}				t_triangle;

typedef struct s_sphere
{
	t_third	center;
	double	radius;
}				t_sphere;

typedef struct s_ray
{
	t_third	origin;
	t_third	direction;
}				t_ray;

typedef struct s_inter
{
	t_third		hit_point;
	t_third		hit_normal;
	t_list		*objects;
	t_object	*closest_object;
	t_ray		sent;
}				t_inter;

typedef struct s_image {
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_info
{
	t_scene		*scene;
	int			camera_number;
	void		*id;
	void		*window;
	t_image		image;
}				t_info;

/* FUNCTIONS */

/* main.c */
t_third			mult_matrix(t_third p, t_matrix m);
t_matrix		direction_view(t_third origin, t_third cam_vector);

/* mini_rt.c */
void			mini_rt(char *filename, int save);
int				replay_render(int key, t_info *info);
int				close_window(t_info *info);
void			render(int camera_number, t_info *info, int save);
void			shoot_rays(t_info *info, int save);

/* checkin.c */
int				check_normal(t_third n);
void			parse_coords(t_third *point, char *field, char *errmsg);
void			parse_color2(t_color2 *result, char *field, char *errmsg);
int				check_color2(t_color2 c);

/* color.c */
int				color_to_int(t_color color);
t_color			int_to_color(int color);

/* color_helper.c */
int				to_int(t_color2 a);
t_color2		color2_coeff(t_color2 a, double coeff);
t_color2		color2_mult(t_color2 a, t_color2 b);
t_color2		color2_add(t_color2 a, t_color2 b);

/* color_utils.c */
t_color2		from_rgb(int r, int g, int b);
t_color2		from_color(t_color a);
t_color2		int_color(int color);

/* cr_buf.c */
t_pixel			**create_buffer(int height, int width);
void			free_buffer(t_pixel **buffer, int height);
t_pixel			pix_from_int(int color);

/* cylinder.c */
t_cylinder		*new_cylinder(t_third p, t_third normal, double radius,
					double height);
void			inseq_cyl(double *t, double *t0, double *t1);
t_third			get_cylinder_normal(t_third point, t_cylinder cylinder);
int				intersect_cylinder(t_ray ray, t_cylinder cylinder, double *t);
void			check_t(double *t, t_cylinder cylinder, t_ray ray);
int				cyl_get_roots(double *t0, double *t1, t_cylinder cylinder,
					t_ray ray);
int				intersect_cylinder(t_ray ray, t_cylinder cylinder, double *t);

/* draw.c */
void			*ft_memset(void *b, int c, size_t len);
void			fill_header(unsigned char *header);
void			fill_sizes(unsigned char *header, unsigned int height,
					unsigned int width);
void			write_file(unsigned int height, unsigned int width,
					t_pixel **pixels, int fd);
int				write_bmp(char *filename, unsigned int width,
					unsigned int height, t_pixel **pixels);

/* equation.c */
void			swap_doubles(double *a, double *b);
t_qparams		new_qparams(double a, double b, double c);
int				solve_quadratic(t_qparams params, double *x0, double *x1);

/* ft_atoi_plus.c */
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
double			ten_to(int pow);
double			dot_part(char *str, int *len);
double			ft_atod(char *str);
void			ft_atod_helper(char *str, int *i, double *nbr);

/* ft_split.c */
char			**ft_split(char const *s, char c);
void			ft_split_helper(char const *s, size_t *i, char c);

/* gnl.c & gnl_helper */
int				get_next_line(int fd, char **line);
int				ft_strlen(char *str);
char			*resize(t_memory *memory);
int				find_nl(t_memory memory);
int				ft_gnl_hell(char **str);

/* intersect.c */
t_inter			new_inter(t_third hit_point, t_third hit_normal,
					t_object *closest_object, t_ray sent);
int				intersect(t_ray sent, t_object *object, double *t);
int				intersect_with_all(t_list *objects, t_ray sent,
					t_object **closest_object, double *t_min);

/* list_utils.c */
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

/* object_parse.c */
void			parse_sphere(t_scene *scene, char **splitted);
void			parse_square(t_scene *scene, char **splitted);
void			parse_triangle(t_scene *scene, char **splitted);
void			parse_cylinder(t_scene *scene, char **splitted);
void			parse_plane(t_scene *scene, char **splitted);

/* parsein.c */
void			parse_resolution(t_scene *scene, char **splitted);
void			parse_ambient(t_scene *scene, char **splitted);
void			parse_camera(t_scene *scene, char **splitted);
void			parse_light(t_scene *scene, char **splitted);

/* parser.c */
t_scene			*parse_file(char *path);
void			check_scene(t_scene *scene);
void			init_scene(t_scene *scene);
void			parse_line(t_scene *scene, char **splitted);

/* parser_helper.c */
int				open_file(char *path);
void			handle_error(char *errormsg);
int				line_fields(char **splitted);

/* plane.c */
t_plane			*new_plane(t_third p0, t_third normal);
t_third			get_plane_normal(t_plane plane);
int				intersect_plane(t_ray ray, t_plane plane, double *t);

/* ray.c */
t_ray			create_ray(t_third origin, t_third direction);
t_ray			ray_to_pixel(int x, int y, t_scene *sene);

/* scene_check.c */
void			check_scene(t_scene *scene);
int				allowed_symbol(char c);
int				check_line(char *line);

/* shaders.c */
t_third			get_normal(t_third point, t_object *object);
t_color2		light_contribution(t_light light, t_inter inter, t_scene scene);
t_color2		shade(t_scene *scene, t_ray sent, t_object *closest_object,
					double t_min);
int				get_color(t_scene *scene, t_ray sent);
t_color2		mix_colors(t_light light, double coeff, t_inter inter);

/* spec.c */
double			spec_coeff(t_light light, t_inter inter);
t_color2		specular(t_light light, t_inter inter);

/* sphere.c */
t_sphere		*new_sphere(t_third center, double radius);
t_third			get_sphere_normal(t_third point, t_sphere sphere);
int				intersect_sphere(t_ray ray, t_sphere sphere, double *t);
int				get_roots(double *t0, double *t1, t_ray ray, t_sphere sphere);

/* square.c */
t_square		*new_square(t_third center, t_third normal, double length);
t_third			get_square_normal(t_square square);
int				intersect_square(t_ray ray, t_square square, double *t);

/* third.c */
t_third			create_v3(double x, double y, double z);
double			vector_len(t_third vector);
double			dot_product(t_third a, t_third b);
void			normalize_vector(t_third *vector);

/* third_helper.c */
t_third			substract(t_third vec1, t_third vec2);
t_third			v3_add(t_third vec1, t_third vec2);
t_third			v3_multiply(t_third vec1, double x);
t_third			cross_product(t_third a, t_third b);

/* triangle.c */
t_triangle		*new_triangle(t_third a, t_third b, t_third c);
t_third			get_triangle_normal(t_triangle triangle);
int				check_edges(t_triangle triangle, t_third p, t_third n);
int				intersect_triangle(t_ray ray, t_triangle triangle, double *t);

#endif