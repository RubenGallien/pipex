/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubengallien <rubengallien@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:38:59 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/18 17:14:48 by rubengallie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	other_pipe(int **fd, t_pipex *pipex)
{
	dup2(fd[pipex->id - 1][0], STDIN_FILENO);
	dup2(fd[pipex->id][1], STDOUT_FILENO);
}

void	close_pipeline(int **fd_end, int i)
{
	while (i--)
		(close(fd_end[i][0]), close(fd_end[i][1]), free(fd_end[i]));
	free(fd_end);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	**pipeline(int n)
{
	int	**fd_end;
	int	i;

	i = 0;
	fd_end = malloc(sizeof(int *) * n);
	if (!fd_end)
		return (0);
	while (n > i)
	{
		fd_end[i] = malloc(sizeof(int) * 2);
		if (!fd_end[i] || pipe(fd_end[i]))
		{
			if (!fd_end[i])
				free(fd_end[i]);
			close_pipeline(fd_end, i);
		}
		i++;
	}
	return (fd_end);
}

char	**find_cmd(char **envp, char *cmd)
{
	int		i;
	char	**all_path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	all_path = ft_split(envp[i] + 6, ':');
	i = -1;
	while (all_path[++i])
	{
		all_path[i] = ft_strjoin(all_path[i], "/");
		all_path[i] = ft_strjoin(all_path[i], cmd);
	}
	i = -1;
	return (all_path);
}
