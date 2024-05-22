/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:00:22 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/22 18:22:38 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_here_doc(t_pipex *pipex, char **av)
{
	(void)pipex;
	if (av[1] && ft_strncmp("here_doc", av[1], 9) == 0)
		pipex->doc = 1;
	else
		pipex->doc = 0;
}

void	check_null(char **cmd, char **all_path)
{
	if (!ft_strncmp(cmd[0], " ", 1))
	{
		ft_putstr_fd("command not found: ", 2);
		ft_free_tab(cmd);
		ft_free_tab(all_path);
		exit(0);
	}
}

void	permissions(char *infile, char *outfile, t_pipex pipex)
{
	(void)outfile;
	if (pipex.doc == 0)
	{
		if (pipex.id == 0 && access(infile, R_OK))
		{
			ft_putstr_fd("Permission denied", 2);
			exit(1);
		}
		if (pipex.n == pipex.id && access(outfile, W_OK))
		{
			ft_putstr_fd("Permission denied", 2);
			exit(1);
		}
	}
}

void	ft_access(char **all_path, char **cmd, char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp && all_path[i])
	{
		if (!access(all_path[i], F_OK | X_OK))
		{
			path = ft_strdup(all_path[i]);
			ft_free_tab(all_path);
			execve(path, cmd, envp);
		}
		i++;
	}
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(cmd[0], 2);
	ft_free_tab(cmd);
	ft_free_tab(all_path);
	exit(127);
}

void	exec(char *cmds, char **envp)
{
	char	**cmd;
	char	**all_path;

	all_path = NULL;
	cmd = ft_split(cmds, ' ');
	if (cmd && cmd[0] && !ft_strchr(cmd[0], '/'))
	{
		all_path = find_cmd(envp, cmd[0]);
		ft_access(all_path, cmd, envp);
	}
	else
	{
		if (cmd && cmd[0] && !access(cmd[0], F_OK | X_OK))
			execve(cmd[0], cmd, envp);
		else if (cmd && cmd[0])
		{
			ft_putstr_fd("No such file or directory :", 2);
			ft_putendl_fd(cmd[0], 2);
		}
		else
			ft_putstr_fd("command not found:\n", 2);
		ft_free_tab(all_path);
		ft_free_tab(cmd);
		exit(127);
	}
}
