/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:59:52 by clornel           #+#    #+#             */
/*   Updated: 2022/01/15 16:59:53 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_alg	*lst_new(int content)
{
	t_alg	*the_new;

	the_new = (t_alg *)malloc(sizeof(t_alg));
	if (!the_new)
		return (NULL);
	the_new->num = content;
	the_new->next = NULL;
	return (the_new);
}
