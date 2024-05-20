/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:00:22 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/20 18:03:01 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	permissions(char *infile, char *outfile, t_pipex pipex)
{
	(void)outfile;
	if (pipex.doc == 0)
	{
		if (pipex.id == 0 && access(infile, R_OK))
			exit(0);
		if (pipex.n == pipex.id && access(outfile, W_OK))
			exit(0);
	}
}

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
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(cmd[0], 2);
	exit(0);
}

void	exec(char *cmds, char **envp)
{
	char	**cmd;
	char	**all_path;

	all_path = NULL;
	cmd = ft_split(cmds, ' ');
	if (!ft_strchr(cmd[0], '/'))
	{
		all_path = find_cmd(envp, cmd[0]);
		ft_access(all_path, cmd, envp);
	}
	else
	{
		if (!access(cmd[0], F_OK | X_OK))
			execve(cmd[0], cmd, envp);
		else
		{
			ft_putstr_fd("pipex: command not found: ", 2);
			ft_putendl_fd(cmd[0], 2);
			exit(0);
		}
	}
}
