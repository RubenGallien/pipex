/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:49:31 by rgallien          #+#    #+#             */
/*   Updated: 2024/02/03 18:42:28 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_ligne(char	*tmp)
{
	int		i;
	int		j;
	char	*ligne;

	i = 0;
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	ligne = malloc(sizeof(char) * (i + 1) + 1);
	if (!ligne)
		return (NULL);
	while (j <= i)
	{
		ligne[j] = tmp[j];
		j++;
	}
	ligne[j] = '\0';
	free(tmp);
	return (ligne);
}

void	shift_stash(char	*stash)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		stash[0] = '\0';
		return ;
	}
	while (stash[i + j])
	{
		stash[j] = stash[i + j + 1];
		j++;
	}
	stash[j] = '\0';
	return ;
}

char	*read_fd(char	*stash, int fd)
{
	int		i;
	char	*tmp;

	tmp = dup_str(stash);
	while (!found_return(tmp, '\n'))
	{
		i = read(fd, stash, BUFFER_SIZE);
		if (i <= 0)
			return (tmp);
		stash[i] = '\0';
		tmp = ft_join(tmp, stash);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1] = {'\0'};
	char		*ligne;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	tmp = read_fd(stash, fd);
	if (!stash[0])
	{
		free(tmp);
		return (NULL);
	}
	ligne = fill_ligne(tmp);
	shift_stash(stash);
	return (ligne);
}
