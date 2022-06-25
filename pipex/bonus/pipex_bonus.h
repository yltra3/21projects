/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:09:30 by clornel           #+#    #+#             */
/*   Updated: 2022/01/20 14:09:30 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "../GNL/get_next_line.h"

typedef struct s_pipexb
{
	int		here_doc;
	int		infile;
	int		outfile;
	int		cmd_count;
	int		fd_count;
	int		*fds;
	char	*cmd;
	char	**cmd_args;
	char	*envpath;
	char	**paths_of_cmd;
	int		c;
	pid_t	pid;
}	t_pipexb;

void	here_doc(char *limiter, t_pipexb *pipex);
int		argin(char *arg, t_pipexb *pipex);
void	msg_err(char *str);
void	bclose_pipes(t_pipexb *pipex);
void	bparent_free(t_pipexb *pipex);
void	bchild_free(t_pipexb *pipex);
void	bfree_struct(t_pipexb *pipex);
void	child_fork(t_pipexb pipex, char **argv, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*find_path(char **envp);
void	binfile(char **argv, t_pipexb *pipex);
void	boutfile(int argc, char **argv, t_pipexb *pipex);

#endif