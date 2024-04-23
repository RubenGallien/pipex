/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:02:08 by rgallien          #+#    #+#             */
/*   Updated: 2023/11/17 15:29:08 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	startdetect(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (set[j] && s1[i])
	{
		if (s1[i] == set[j])
		{
			count++;
			j = 0;
			i++;
		}
		else
		{
			j++;
		}
	}
	return (count);
}

static int	enddetect(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	i = ft_strlen(s1) - 1;
	while (i >= startdetect(s1, set) && set[j])
	{
		if (set[j] == s1[i])
		{
			count++;
			j = 0;
			i--;
		}
		else
			j++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		debut;
	int		fin;
	char	*ptr;

	if (!s1)
		return (NULL);
	debut = startdetect(s1, set);
	fin = enddetect(s1, set);
	ptr = ft_substr(s1, debut, ft_strlen(s1) - (debut + fin));
	return (ptr);
}
