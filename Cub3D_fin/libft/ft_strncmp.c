/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:07:34 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/20 08:02:19 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((--n) && (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
