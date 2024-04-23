/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:49:42 by rgallien          #+#    #+#             */
/*   Updated: 2024/02/03 18:41:35 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	found_return(char *stash, char c)
{
	int		i;

	i = 0;
	if (!stash)
	{
		return (0);
	}
	while (stash[i])
	{
		if (stash[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_join(char *stash, char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (len_str(stash) + len_str(buffer) + 1));
	if (!str)
		return (NULL);
	while (stash && stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	while (buffer[j])
	{
		str[i + j] = buffer[j];
		j++;
	}
	str[i + j] = '\0';
	free(stash);
	return (str);
}

char	*dup_str(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
