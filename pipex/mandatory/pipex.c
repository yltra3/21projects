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

#include "pipex.h"

void	close_pipes(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		msg_err("invalid number of args");
	infile(argv, &pipex);
	outfile(argc, argv, &pipex);
	if (pipe(pipex.fd) < 0)
		msg_err("create pipe err");
	pipex.envpath = find_path(envp);
	pipex.paths_of_cmd = ft_split(pipex.envpath, ':');
	if (!pipex.paths_of_cmd)
		free_struct(&pipex);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	parent_free(&pipex);
	return (0);
}
