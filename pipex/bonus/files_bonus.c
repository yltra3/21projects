/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:59:47 by clornel           #+#    #+#             */
/*   Updated: 2022/01/20 15:59:49 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	msg_err(char *str)
{
	perror(str);
	exit (1);
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	here_doc(char *limiter, t_pipexb *pipex)
{
	int		file;
	char	*buf;

	file = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file < 0)
		msg_err("here_doc create error");
	while (1)
	{
		buf = get_next_line(0);
		if (!buf)
			exit(1);
		if (!ft_strncmp(limiter, buf, ft_strlen(limiter) + 1))
			break ;
		write(file, buf, ft_strlen(buf));
		write(file, "\n", 1);
		free(buf);
	}
	free(buf);
	close(file);
	pipex->infile = open("here_doc", O_RDONLY);
	if (pipex->infile < 0)
	{
		unlink("here_doc");
		msg_err("here_doc open error");
	}
}

void	binfile(char **argv, t_pipexb *pipex)
{
	if (pipex->here_doc)
		here_doc(argv[2], pipex);
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
			msg_err("infile open error");
	}
}

void	boutfile(int argc, char **argv, t_pipexb *pipex)
{
	if (pipex->here_doc)
	{
		pipex->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY
				|O_APPEND, 0644);
		if (pipex->outfile < 0)
			msg_err("here_doc outfile open error");
	}
	else
	{
		pipex->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (pipex->outfile < 0)
			msg_err("outfile open error");
	}
}
