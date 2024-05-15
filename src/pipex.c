/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:37:38 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/15 18:40:51 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		write(2, "')\n", 3);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		**fd;

	(void)envp;
	if (ac < 5)
		return (-1);
	pipex.doc = 0;
	pipex.n = ac - 4;
	fd = pipeline(pipex.n);
	if (ft_strncmp("here_doc", av[1], 9) == 0)
		ft_here_doc(av[2], &pipex, fd);
	make_children(&pipex);
	if (pipex.pid)
	{
		close_pipeline(fd, pipex.n + pipex.doc);
	}
	if (!pipex.pid)
	{
		choose_pipe(fd, &pipex); // dup2
		// exec_cmd (trouver le path + cmd + execve)
		close_pipeline(fd, pipex.n + pipex.doc);
	}
	// ft_exec(av, envp, &pipex);
	// find_cmd(envp, av[1]);
	return (0);
}
