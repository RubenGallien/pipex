/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:00:22 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/16 13:53:09 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void choose_pipe(int **fd, t_pipex *pipex)
{
	if (pipex->id == 0 && pipex->doc == 1)
	{
		dup2(fd[pipex->n][0], STDIN_FILENO);
		dup2(fd[0], fd[1]);
	}
	else if (pipex->id == 0)
	{

	}

}
