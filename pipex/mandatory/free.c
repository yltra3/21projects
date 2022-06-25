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

#include "pipex.h"

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->paths_of_cmd[i])
	{
		free(pipex->paths_of_cmd[i]);
		i++;
	}
	free(pipex->paths_of_cmd);
}

void	child_free(t_pipex *pipex)
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

void	free_struct(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	free(pipex->fd);
	perror("envp error");
	exit(1);
}
