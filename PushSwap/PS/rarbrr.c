/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarbrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:48:03 by clornel           #+#    #+#             */
/*   Updated: 2022/01/15 09:48:04 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_swap *swap, int i)
{
	if (swap->a != NULL)
	{
		if (swap->a->next != NULL)
		{
			swap->temp = swap->a;
			swap->a = swap->a->next;
			ft_lstadd_back(&swap->a, swap->temp);
			swap->temp->next = NULL;
		}
	}
	if (i == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_swap *swap, int i)
{
	if (swap->b != NULL && swap->b->next != NULL)
	{
		swap->temp = swap->b;
		swap->b = swap->b->next;
		ft_lstadd_back(&swap->b, swap->temp);
		swap->temp->next = NULL;
	}
	if (i == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_swap *swap, int i)
{
	ra(swap, 0);
	rb(swap, 0);
	if (i == 1)
		ft_putstr_fd("rr\n", 1);
}
