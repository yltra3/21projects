/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarrbrrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:02:39 by clornel           #+#    #+#             */
/*   Updated: 2022/01/15 10:02:41 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_swap *swap, int i)
{
	t_alg	*t;
	int		size;

	if (swap->a != NULL && swap->a->next != NULL)
	{
		t = swap->a;
		swap->temp = lst_last(swap->a);
		size = ft_lstsize(swap->a);
		while ((size - 2) != 0)
		{
			t = t-> next;
			--size;
		}
		t->next = NULL;
		swap->temp->next = swap->a;
		swap->a = swap->temp;
	}
	if (i == 1)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_swap *swap, int i)
{
	t_alg	*t;
	int		size;

	if (swap->b != NULL && swap->b->next != NULL)
	{
		t = swap->b;
		swap->temp = lst_last(swap->b);
		size = ft_lstsize(swap->b);
		while ((size - 2) != 0)
		{
			t = t->next;
			--size;
		}
		t->next = NULL;
		swap->temp->next = swap->b;
		swap->b = swap->temp;
	}
	if (i == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_swap *swap, int i)
{
	rra(swap, 0);
	rrb(swap, 0);
	if (i == 1)
		ft_putstr_fd("rrr\n", 1);
}
