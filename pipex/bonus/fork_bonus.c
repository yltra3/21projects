/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:49:12 by clornel           #+#    #+#             */
/*   Updated: 2022/01/21 12:49:14 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

static void	sub_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	child_fork(t_pipexb pipex, char **argv, char **envp)
{
	pipex.pid = fork();
	if (!pipex.pid)
	{
		if (pipex.c == 0)
			sub_dup2(pipex.infile, pipex.fds[1]);
		else if (pipex.c == pipex.cmd_count - 1)
			sub_dup2(pipex.fds[2 * pipex.c - 2], pipex.outfile);
		else
			sub_dup2(pipex.fds[2 * pipex.c - 2], pipex.fds[2 * pipex.c + 1]);
		bclose_pipes(&pipex);
		pipex.cmd_args = ft_split(argv[2 + pipex.here_doc + pipex.c], ' ');
		pipex.cmd = get_cmd(pipex.paths_of_cmd, pipex.cmd_args[0]);
		if (!pipex.cmd)
		{
			bchild_free(&pipex);
			msg_err("cmd get error");
		}
		execve(pipex.cmd, pipex.cmd_args, envp);
	}
}
