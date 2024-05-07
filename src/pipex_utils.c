/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:18:28 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/07 19:13:40 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char *find_env(char **envp)
{
	char *str;
	int	i;
	int	j;

	i = 0;
	while(envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		str = ft_substr(envp[i], 0, j);
		if (ft_strncmp(str, "PATH", ft_strlen("PATH")) == 0)
			return (free(str), envp[i]);
		free(str);
		str = NULL;
		i++;
	}
	return (NULL);
}
