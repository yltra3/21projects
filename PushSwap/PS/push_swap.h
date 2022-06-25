/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:12:09 by clornel           #+#    #+#             */
/*   Updated: 2022/01/14 11:12:11 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_alg
{
	struct s_alg	*next;
	int				num;
	int				index;
	int				indicator;
	int				next_index;
	int				steps;
	int				first_i;
	int				first_step;
	int				temp_steps;
}	t_alg;

typedef struct s_swap
{
	t_alg	*a;
	t_alg	*b;
	t_alg	*temp;
	t_alg	init;
}	t_swap;

void	error_exit(t_swap *swap);
void	parser(t_swap *swap, int argc, char **argv);
void	indexes(t_swap *swap);
void	pa(t_swap *swap, int i);
void	pb(t_swap *swap, int i);
void	ra(t_swap *swap, int i);
void	rb(t_swap *swap, int i);
void	rr(t_swap *swap, int i);
void	sa(t_swap *swap, int i);
void	sb(t_swap *swap, int i);
void	ss(t_swap *swap, int i);
void	rra(t_swap *swap, int i);
void	rrb(t_swap *swap, int i);
void	rrr(t_swap *swap, int i);
void	three_arg(t_swap *swap);
void	algorithm(t_swap *swap);
int		search(t_swap *swap, int index);
void	number_steps(t_swap *swap);
void	swap_st(t_swap *swap);
void	lst_free(t_alg *nums);
int		ft_lstsize(t_alg *nums);
void	ft_lst_clear(t_alg **nums);
t_alg	*lst_last(t_alg *nums);
void	ft_lstadd_back(t_alg **nums, t_alg *new);
t_alg	*lst_new(int content);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		is_space(char s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

#endif