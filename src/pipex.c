/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:37:38 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/19 16:28:54 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	choose_pipe(int **fd, t_pipex *pipex, char *infile, char *outfile)
{
	int	in;
	int	out;

	if (pipex->id == 0)
	{
		if (pipex->doc == 1)
			dup2(fd[pipex->n][0], 0);
		else
		{
			in = open(infile, O_RDONLY);
			dup2(in, 0);
		}
		dup2(fd[pipex->id][1], 1);
	}
	else if (pipex->id == pipex->n)
	{
		if (!pipex->doc)
			out = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0777);
		else
			out = open(outfile, O_CREAT | O_APPEND | O_WRONLY, 0777);
		dup2(fd[pipex->id - 1][0], 0);
		dup2(out, 1);
	}
	else
		other_pipe(fd, pipex);
}

void	ft_wait(t_pipex pipex)
{
	int	i;

	i = 0;
	while (i < pipex.id)
	{
		wait(NULL);
		i++;
	}
}

void	make_children(t_pipex *pipex)
{
	pipex->id = -1;
	pipex->pid = -1;
	while (pipex->pid && pipex->id < pipex->n)
	{
		pipex->pid = fork();
		pipex->id++;
	}
	while (pipex->pid && pipex->id > 0)
	{
		pipex->pid = wait(NULL);
		pipex->id--;
	}
}

void	ft_here_doc(char *end, t_pipex *pipex, int **fd)
{
	char	*str;

	pipex->doc = 1;
	pipex->n--;
	str = get_next_line(0);
	while (str && ft_strncmp(end, str, ft_strlen(str) - 1) != 0)
	{
		write(fd[pipex->n][1], str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
	}
	if (str)
		free(str);
	else
	{
		write(2, \
		"bash: warning: here-document delimited by end-of-file (wanted `", 63);
		write(2, end, ft_strlen(end));
		write(2, "')", 3);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		**fd;

	if (ac < 5)
		return (0);
	pipex.err = 0;
	pipex.doc = 0;
	pipex.n = ac - 4;
	fd = pipeline(pipex.n);
	if (ft_strncmp("here_doc", av[1], 9) == 0)
		ft_here_doc(av[2], &pipex, fd);
	make_children(&pipex);
	if (pipex.pid)
	{
		close_pipeline(fd, pipex.n + pipex.doc);
		ft_wait(pipex);
	}
	if (!pipex.pid)
	{
		choose_pipe(fd, &pipex, av[1], av[ac - 1]);
		exec(av[pipex.id + 2 + pipex.doc], envp, pipex);
		close_pipeline(fd, pipex.n + pipex.doc);
	}
	return (pipex.err);
}
