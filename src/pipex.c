/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:37:38 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/12 19:36:39 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_here_doc(char *end)
{
	char *str;

	str = get_next_line(0);
	while (str && ft_strncmp(end, str, ft_strlen(str) - 1) != 0)
	{
		free(str);
		str = get_next_line(0);
	}
	free(str);
}

int	main(int ac, char **av, char **envp)
{
	int		pipeline;
	char	**all_path;
	if (ac < 5)
		return (0);
	if (ft_strncmp("here_doc", av[1], 9) == 0)
		ft_here_doc(av[2]);
	pipeline = ac - 4;
	all_path = ft_split(find_env(envp) + ft_strlen("PATH="), ':');
	printf("%d\n", pipeline);
	return (ft_free_tab(all_path), 0);
}
