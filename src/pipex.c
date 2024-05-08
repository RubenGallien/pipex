/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:37:38 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/08 12:24:45 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		pipeline;
	char	**all_path;
	int		i;

	i = 0;
	if (!envp[0])
		return (-1);
	pipeline = ac - 4;
	all_path = ft_split(find_env(envp) + ft_strlen("PATH="), ':');
	while (all_path[i])
	{
		ft_printf("%s\n", all_path[i]);
		i++;
	}
	ft_printf("nb_args = %d\n%s\n", pipeline, av[0]);
	return (ft_free_tab(all_path), 0);
}
