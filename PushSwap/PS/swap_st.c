/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:36:18 by clornel           #+#    #+#             */
/*   Updated: 2022/01/15 12:36:19 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_st(t_swap *swap)
{
	t_alg	*temp_st;
	int		i;

	swap->temp = swap->b;
	while (swap->temp->index != swap->init.first_i)
		swap->temp = swap->temp->next;
	temp_st = swap->a;
	while (temp_st->index != swap->temp->next_index)
		temp_st = temp_st->next;
	if (temp_st->indicator == swap->temp->indicator)
	{
		if (temp_st->steps > swap->temp->steps)
			i = swap->temp->steps;
		else
			i = temp_st->steps;
		while (i--)
		{
			if (temp_st->indicator == 1)
				rr(swap, 1);
			else
				rrr(swap, 1);
		}
	}
}
