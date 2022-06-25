/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:07:33 by clornel           #+#    #+#             */
/*   Updated: 2022/01/20 14:07:35 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	creat_pipes(t_pipexb *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count - 1)
	{
		if (pipe(pipex->fds + 2 * i) < 0)
			bparent_free(pipex);
		i++;
	}
}

void	bclose_pipes(t_pipexb *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->fd_count))
	{
		close(pipex->fds[i]);
		i++;
	}
}

int	argin(char *arg, t_pipexb *pipex)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipexb	pipex;

	if (argin(argv[1], &pipex) > argc)
		return (-1);
	binfile(argv, &pipex);
	boutfile(argc, argv, &pipex);
	pipex.cmd_count = argc - 3 - pipex.here_doc;
	pipex.fd_count = 2 * (pipex.cmd_count - 1);
	pipex.fds = (int *)malloc(pipex.fd_count * sizeof(int));
	if (!pipex.fds)
		perror("didnt malloc fds");
	pipex.envpath = find_path(envp);
	pipex.paths_of_cmd = ft_split(pipex.envpath, ':');
	if (!pipex.paths_of_cmd)
		bfree_struct(&pipex);
	creat_pipes(&pipex);
	pipex.c = -1;
	while (++(pipex.c) < pipex.cmd_count)
		child_fork(pipex, argv, envp);
	bclose_pipes(&pipex);
	waitpid(-1, NULL, 0);
	bparent_free(&pipex);
	return (0);
}
