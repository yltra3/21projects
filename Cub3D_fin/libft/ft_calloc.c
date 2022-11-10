/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:45:40 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/20 15:14:25 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*m;

	m = (void *)malloc(count * size);
	if (!m)
		return (0);
	ft_bzero(m, count * size);
	return (m);
}
