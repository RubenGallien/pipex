/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:16:29 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/23 13:35:34 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(char **cmd, char **all_path)
{
	if (access(cmd[0], F_OK))
		return (0);
	if (access(cmd[0], X_OK))
	{
		ft_putstr_fd("Permission denied", 2);
		ft_free_tab(all_path);
		ft_free_tab(cmd);
		exit(126);
	}
	return (1);
}

int	count_hd(char *str, char *end)
{
	int	s1;
	int	s2;

	s1 = ft_strlen(str) - 1;
	s2 = ft_strlen(end);
	if (s1 > s2)
		return (s1);
	else
		return (s2);
}
