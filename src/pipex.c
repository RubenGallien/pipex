/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubengallien <rubengallien@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:37:38 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/13 17:48:37 by rubengallie      ###   ########.fr       */
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

	if (ac < 5)
		return (0);
	if (ft_strncmp("here_doc", av[1], 9) == 0)
		ft_here_doc(av[2]);
	pipeline = ac - 4;
	find_cmd(envp);
	int pid = -1;
    int id = -1;
    while (pid && id < pipeline)
    {
        pid = fork();
        id++;
    }
    while (pid && id > 0)
    {
        printf("hello from parent, id = %d, pid = %d\n", id, pid);
        pid = wait(NULL);
        id--;
    }
    if (!pid)
        printf("hello from child %d, pid = %d \n", id, pid);
	return (0);
}
