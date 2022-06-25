/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:17:55 by clornel           #+#    #+#             */
/*   Updated: 2021/11/10 19:17:57 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_string(int fd, char *dst);
char	*ft_returned(const char *s);
char	*ft_new_line(char *str);
char	*ft_cut_dst(char *dst);
char	*gnl_join(char *s1, char *s2);
size_t	ft_strlen(const char *s);
#endif