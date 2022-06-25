/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:20:19 by clornel           #+#    #+#             */
/*   Updated: 2021/10/30 17:20:21 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_flags
{
	va_list	args;
	int		width;
	int		zero;
	int		dot;
	int		dash;
	int		plus;
	int		length;
	int		sign;
	int		is_printed;
	int		persent;
	int		space;
	int		reshetka;
	int		presision;
	int		string;
	int		is_zero;
	char	*smhex;
	char	*bghex;
}			t_flags;

void	ft_work_with_zero(t_flags *init);
void	ft_work_with_space(t_flags *init, long a, int alength);
void	ft_notdash_uns(t_flags *init, char *f, unsigned int a);
char	*ft_allocate_uns(t_flags *init, int alength, int i);
char	*ft_allocate_uns_over26_1(int alength);
int		ft_some_uns_flags(t_flags *init, unsigned int a);
void	ft_notdash_pointer(t_flags *init, unsigned long a, char *f);
int		ft_pointer_someflags(t_flags *init, unsigned long a);
char	*ft_allocate_pointer1(t_flags *init);
int		pr_putstr(char *str);
void	pr_bzero(void *s, size_t n);
int		pr_strlen(const char *s);
int		pr_isdigit(int c);
void	*pr_calloc(size_t nmemb, size_t size);
void	ft_print_int_notdash_over26_1(t_flags *init, char *f);
char	*ft_allocate_int_over26_1(t_flags *init, int alength);
int		ft_print_int_some_flags(t_flags *init, long a);
char	*ft_int_digit_memory(t_flags *init, int alength);
void	ft_print_int_dash(t_flags *init, char *f, long a, int alength);
void	ft_print_int_notdash(t_flags *init, char *f, int alength);
void	ft_print_string_over26_3(t_flags *init, char *a, char *f);
char	*ft_print_string_over26_4(t_flags *init, char *a);
char	*ft_dotpresision_str(t_flags *init);
void	ft_print_string_over26_1(t_flags *init, char *a, char *f);
void	ft_print_string_over26_2(t_flags *init, char *a, char *f);
int		ft_check_dich_hex(t_flags *init, unsigned int a);
char	*ft_allocate_fhex(t_flags *init, int alength);
void	ft_parse_dash_printfbghex(t_flags *init, char *f, unsigned int a,
			int alength);
void	ft_parse_notdash_printfbghex(t_flags *init, char *f, unsigned int a);
void	ft_parse_dash_printfsmhex(t_flags *init, char *f, unsigned int a,
			int alength);
void	ft_parse_notdash_printfsmhex(t_flags *init, char *f, unsigned int a);
char	*ft_parse_string_printfperc(t_flags *init, char *f);
void	ft_print_percent(t_flags *init);
int		ft_print_with_flags_printfperc(t_flags *init, char *f);
int		ft_print_with_flags_printfpointer(t_flags *init, char *f,
			unsigned long a, int alength);
char	*ft_parse_string_printfuns(t_flags *init, char *f);
void	ft_print_pointer(t_flags *init);
void	ft_print_uns(t_flags *init);
void	ft_print_smhex(t_flags *init);
void	ft_print_bghex(t_flags *init);
char	*ft_parse_string_printfhex(t_flags *init, char *f);
void	ft_parse_dash_printfbghex(t_flags *init, char *f, unsigned int a,
			int alength);
void	ft_parse_dash_printfbghex(t_flags *init, char *f, unsigned int a,
			int alength);
int		ft_print_with_flags_printfuns(t_flags *init, char *f, unsigned int a,
			int alength);
int		ft_print_with_flags_printfsmhex(t_flags *init, char *f, unsigned int a,
			int alength);
int		ft_print_with_flags_printfbghex(t_flags *init, char *f, unsigned int a,
			int alength);
int		ft_print_with_flags_printfid(t_flags *init, char *f, long a,
			int alength);
char	*ft_parse_string_printfid(t_flags *init, char *f);
char	*ft_a_is_null_printfs(char *s);
char	*ft_memory_printfs(t_flags *init, char *a);
void	ft_check_dot_dash_printfs(t_flags *init, char *a, char *f);
int		ft_check_low_width_printfs(t_flags *init, char *a, char *f);
void	ft_print(t_flags *init, const char *s, int pos);
int		ft_init_format(t_flags *init, const char *s, int pos);
int		ft_printf(const char *s, ...);
t_flags	*ft_init_init(t_flags *init);
void	ft_print_string_printfs(t_flags *init);
void	ft_print_char(t_flags *init);
void	ft_print_int(t_flags *init);

#endif
