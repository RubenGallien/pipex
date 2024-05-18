/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubengallien <rubengallien@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:39:14 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/18 17:55:15 by rubengallie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int	pid;
	int	id;
	int	doc;
	int	n;
}	t_pipex;

void	exec(char *cmds, char **envp);
char **find_cmd(char **envp, char *cmd);
void	ft_free_tab(char **tab);
int		**pipeline(int n);
void	choose_pipe(int **fd, t_pipex *pipex, char *infile, char *outfile);
void	close_pipeline(int **fd_end, int i);
void	other_pipe(int **fd, t_pipex *pipex);

#endif