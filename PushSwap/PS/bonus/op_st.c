/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:28:45 by clornel           #+#    #+#             */
/*   Updated: 2022/01/15 17:28:48 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	l;
	int		i;

	l = 0;
	if (len == 0 && h == 0)
		return (0);
	if (n[l] == '\0')
		return ((char *)h);
	while (h[l] != '\0' && l < len)
	{
		i = 0;
		if (h[l] == n[i])
		{
			while (len > i + l && n[i] != '\0' && h[l + i] != '\0'
				&& h[l + i] == n[i])
				i++;
			if (n[i] == '\0')
				return ((char *)h + l);
		}
		l++;
	}
	return (NULL);
}

static void	oper_three(t_swap *swap, char *line, int len)
{
	if (ft_strnstr(line, "rra", len))
		rra(swap, 0);
	else if (ft_strnstr(line, "rrb", len))
		rrb(swap, 0);
	else if (ft_strnstr(line, "rrr", len))
		rrr(swap, 0);
}

static void	oper_two(t_swap *swap, char *line, int len)
{
	if (ft_strnstr(line, "ra", len))
		ra(swap, 0);
	else if (ft_strnstr(line, "rb", len))
		rb(swap, 0);
	else if (ft_strnstr(line, "sa", len))
		sa(swap, 0);
	else if (ft_strnstr(line, "sb", len))
		sb(swap, 0);
	else if (ft_strnstr(line, "pb", len))
		pb(swap, 0);
	else if (ft_strnstr(line, "pa", len))
		pa(swap, 0);
	else if (ft_strnstr(line, "rr", len))
		rr(swap, 0);
	else if (ft_strnstr(line, "ss", len))
		ss(swap, 0);
}

void	filter(t_swap *swap, char *line)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	if (len != 2 && len != 3)
		error_exit(swap);
	i = 0;
	if (line[i] != 'r' && line[i] != 's' && line[i] != 'p')
		error_exit(swap);
	if (line[i] == 'r' && line[i + 1] != 'r' && line[i + 1] != 'a'
		&& line[i + 1] != 'b')
		error_exit(swap);
	if (line[i] == 's' && line[i + 1] != 'a' && line[i + 1] != 'b'
		&& line[i + 1] != 's')
		error_exit(swap);
	if (line[i] == 'p' && (line[i + 1] != 'a' && line[i + 1] != 'b'))
		error_exit(swap);
	if (len == 3)
		if (line[i + 1] != 'r' || (line[i + 2] != 'r' && line[i + 2] != 'a'
				&& line[i + 2] != 'b'))
			error_exit(swap);
}

void	operations_st(t_swap *swap, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len == 3)
		oper_three(swap, line, len);
	else if (len == 2)
		oper_two(swap, line, len);
	else
		error_exit(swap);
}
