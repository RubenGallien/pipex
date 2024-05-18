/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubengallien <rubengallien@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:00:22 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/19 00:10:54 by rubengallie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_access(char **all_path, char **cmd, char **envp)
{
	int		i;

	i = 0;
	while (all_path[i])
	{
		if (!access(all_path[i], F_OK | X_OK))
			execve(all_path[i], cmd, envp);
		i++;
	}
}

void	exec(char *cmds, char **envp)
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
		ft_access(all_path, cmd, envp);
	}
	else
	{
		if (!access(cmd[0], F_OK | X_OK))
			execve(cmd[0], args, envp);
	}
}
