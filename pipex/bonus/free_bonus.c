/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:17:29 by clornel           #+#    #+#             */
/*   Updated: 2022/01/20 20:17:31 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	bparent_free(t_pipexb *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink("here_doc");
	while (pipex->paths_of_cmd[i])
	{
		free(pipex->paths_of_cmd[i]);
		i++;
	}
	free(pipex->paths_of_cmd);
	free(pipex->fds);
}

void	bchild_free(t_pipexb *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	bfree_struct(t_pipexb *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink("here_doc");
	free(pipex->fds);
	perror("envp error");
	exit(1);
}
