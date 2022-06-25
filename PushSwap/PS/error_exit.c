/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:02:15 by clornel           #+#    #+#             */
/*   Updated: 2022/01/14 13:02:16 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_swap *swap)
{
	ft_lst_clear(&swap->a);
	ft_lst_clear(&swap->b);
	ft_putstr_fd("ERROR\n", 2);
	exit(1);
}

void	ko(t_swap *swap)
{
	ft_lst_clear(&swap->a);
	ft_lst_clear(&swap->b);
	ft_putstr_fd("KO\n", 2);
	exit(1);
}
