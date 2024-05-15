/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:39:14 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/15 15:27:45 by rgallien         ###   ########.fr       */
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
	int pid;
	int id;
	int doc;
	int	n;
}	t_pipex;

char	*find_cmd(char **envp, char *cmd);
void	ft_free_tab(char **tab);
int		**pipeline(int n);
void	choose_pipe(int **fd, t_pipex *pipex);
void	close_pipeline(int **fd_end, int i);

#endif