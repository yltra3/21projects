/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:33:30 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/20 16:27:02 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	int		i;
	int		y;

	if (!s1 || !s2)
		return (0);
	i = 0;
	y = 0;
	nstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!nstr)
		return (0);
	while (s1[i] != '\0')
		nstr[y++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		nstr[y++] = s2[i++];
	nstr[y] = '\0';
	return (nstr);
}
