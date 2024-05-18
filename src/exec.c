/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubengallien <rubengallien@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:00:22 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/18 18:27:21 by rubengallie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_access(char **all_path, char **cmd, char **envp)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(cmd[1], ' ');
	while (all_path[i])
	{
		if (!access(all_path[i], F_OK | X_OK))
			execve(cmd[0], args, envp);
		i++;
	}
	ft_free_tab(all_path);
	ft_free_tab(cmd);
	ft_free_tab(args);
	ft_printf("Erreur1\n");
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
		all_path = find_cmd(envp, cmd[0]);
	if (!ft_strchr(cmd[0], '/'))
		ft_access(all_path, cmd, envp);
	else
	{
		if (!access(cmd[0], F_OK | X_OK))
			execve(cmd[0], args, envp);
		else
		{
			ft_free_tab(all_path);
			ft_free_tab(cmd);
			ft_free_tab(args);
			ft_printf("Erreur2\n");
		}
	}
}
