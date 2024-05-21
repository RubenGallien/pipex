/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:37:38 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/21 16:54:13 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	choose_pipe(int **fd, t_pipex *pipex, char *infile, char *outfile)
{
	int	in;
	int	out;

	in = -1;
	out = -1;
	if (pipex->id == 0)
	{
		if (pipex->doc == 1)
			in = fd[pipex->n][0];
		else
			in = open(infile, O_RDONLY);
		dup2(in, 0);
		dup2(fd[pipex->id][1], 1);
	}
	else if (pipex->id == pipex->n)
	{
		if (!pipex->doc)
			out = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0666);
		else
			out = open(outfile, O_CREAT | O_APPEND | O_WRONLY, 0666);
		dup2(fd[pipex->id - 1][0], 0);
		dup2(out, 1);
	}
	else
		other_pipe(fd, pipex);
	if (out >= 0)
		close(out);
	if (in >= 0)
		close(in);
}

int	ft_wait(t_pipex pipex)
{
	int	status;
	int	r;

	r = 0;
	while (pipex.id >= 0)
	{
		if (pipex.pid == wait(&status))
			r = WEXITSTATUS(status);
		pipex.id--;
	}
	return (r);
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
	ft_printf("argc = %d", ac);
	exit(0);
	t_pipex	pipex;
	int		**fd;

	ft_printf("argc = %d", ac);
	write(1, "hello", 5);
	exit(0);
	if (ft_strncmp("here_doc", av[1], 9) == 0)
		pipex.doc = 1;
	else
		pipex.doc = 0;
	if (ac - pipex.doc < 5)
		return (0);
	pipex.err = 0;
	pipex.n = ac - 4;
	fd = pipeline(pipex.n);
	if (ft_strncmp("here_doc", av[1], 9) == 0)
		ft_here_doc(av[2], &pipex, fd);
	make_children(&pipex);
	if (pipex.pid)
	{
		close_pipeline(fd, pipex.n + pipex.doc);
		return (ft_wait(pipex));
	}
	if (!pipex.pid)
	{
		choose_pipe(fd, &pipex, av[1], av[ac - 1]);
		close_pipeline(fd, pipex.n + pipex.doc);
		permissions(av[1], av[ac - 1], pipex);
		exec(av[pipex.id + 2 + pipex.doc], envp);
	}
	return (0);
}
