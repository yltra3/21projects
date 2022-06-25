/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:41:02 by clornel           #+#    #+#             */
/*   Updated: 2022/01/15 09:41:04 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_swap *swap, int i)
{
	t_alg	*t;

	if (swap->b != NULL)
	{
		t = swap->b;
		t = t->next;
		if (swap->a == NULL)
			swap->b->next = NULL;
		else
			swap->b->next = swap->a;
		swap->a = swap->b;
		swap->b = t;
	}
	if (i == 1)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_swap *swap, int i)
{
	t_alg	*t;

	if (swap->a != NULL)
	{
		t = swap->a;
		t = t->next;
		if (swap->b == NULL)
			swap->a->next = NULL;
		else
			swap->a->next = swap->b;
		swap->b = swap->a;
		swap->a = t;
	}
	if (i == 1)
		ft_putstr_fd("pb\n", 1);
}
