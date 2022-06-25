/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:18:01 by clornel           #+#    #+#             */
/*   Updated: 2022/01/15 17:18:03 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	init_struct(t_swap *swap, int argc, char **argv)
{
	swap->a = NULL;
	swap->b = NULL;
	swap->temp = NULL;
	parser(swap, argc, argv);
	indexes(swap);
}

static void	sorted(t_swap *swap)
{
	swap->temp = swap->a;
	if (swap->temp->index == 0)
	{
		while (swap->temp->next != NULL)
		{
			if (swap->temp->index + 1 == swap->temp->next->index)
				swap->temp = swap->temp->next;
			else
				ko(swap);
		}
	}
}

static void	check_sort(t_swap *swap)
{
	int	st_b;

	st_b = ft_lstsize(swap->b);
	if (st_b)
		ko(swap);
	sorted(swap);
}

int	main(int argc, char **argv)
{
	t_swap	swap;
	int		res;
	char	*line;
	int		i;

	i = 0;
	if (argc == 1)
		return (0);
	init_struct(&swap, argc, argv);
	res = get_next_line(&line);
	while (res && res != -1)
	{
		filter(&swap, line);
		operations_st(&swap, line);
		free(line);
		res = get_next_line(&line);
	}
	if (res == -1)
		error_exit(&swap);
	check_sort(&swap);
	write(1, "OK\n", 3);
	ft_lstclear(&swap.a);
	return (0);
}
