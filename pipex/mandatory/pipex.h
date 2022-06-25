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

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "../GNL/get_next_line.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		cmd_count;
	int		fd[2];
	char	*cmd;
	char	**cmd_args;
	char	*envpath;
	char	**paths_of_cmd;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

void	first_child(t_pipex pipex, char *argv[], char *envp[]);
void	second_child(t_pipex pipex, char *argv[], char *envp[]);
void	msg_err(char *str);
void	close_pipes(t_pipex *pipex);
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
void	free_struct(t_pipex *pipex);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*find_path(char **envp);
void	infile(char **argv, t_pipex *pipex);
void	outfile(int argc, char **argv, t_pipex *pipex);

#endif