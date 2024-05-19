/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:00:22 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/19 16:31:42 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_access(char **all_path, char **cmd, char **envp, t_pipex pipex)
{
	int		i;

	i = 0;
	while (all_path[i])
	{
		if (!access(all_path[i], F_OK | X_OK))
			execve(all_path[i], cmd, envp);
		i++;
	}
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(cmd[0], 2);
	exit(pipex.err);
}

void	exec(char *cmds, char **envp, t_pipex pipex)
{
	char	**cmd;
	char	**all_path;
	char	**args;

	all_path = NULL;
	cmd = ft_split(cmds, ' ');
	args = ft_split(cmd[1], ' ');
	if (!ft_strchr(cmd[0], '/'))
	{
		all_path = find_cmd(envp, cmd[0]);
		ft_access(all_path, cmd, envp, pipex);
	}
	else
	{
		if (!access(cmd[0], F_OK | X_OK))
			execve(cmd[0], args, envp);
		else
		{
			ft_putstr_fd("pipex: command not found: ", 2);
			ft_putendl_fd(args[0], 2);
			exit(0);
		}
	}
}
