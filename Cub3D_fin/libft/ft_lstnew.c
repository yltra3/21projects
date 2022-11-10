/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:48:09 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/21 09:55:24 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nl;

	nl = (t_list *)malloc(sizeof(*nl));
	if (!nl)
		return (NULL);
	nl->content = content;
	nl->next = NULL;
	return (nl);
}
