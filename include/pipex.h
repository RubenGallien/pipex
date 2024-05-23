/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:39:14 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/23 13:30:45 by rgallien         ###   ########.fr       */
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
	int	err;
}	t_pipex;

void	exec(char *cmds, char **envp);
char	**find_cmd(char **envp, char *cmd);
void	ft_free_tab(char **tab);
int		**pipeline(int n);
void	choose_pipe(int **fd, t_pipex *pipex, char *infile, char *outfile);
void	close_pipeline(int **fd_end, int i);
void	other_pipe(int **fd, t_pipex *pipex, int in, int out);
void	permissions(char *infile, char *outfile, t_pipex pipex);
void	init_here_doc(t_pipex *pipex, char **av);
int		count_hd(char *str, char *end);
int		check_access(char **cmd, char **all_path);

#endif