/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:57 by rgallien          #+#    #+#             */
/*   Updated: 2023/11/20 18:51:37 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_free(char **strs, int j)
{
	if (!strs[j])
	{
		while (--j >= 0)
			free(strs[j]);
		free(strs);
	}
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*s == c)
			count = 0;
		s++;
	}
	return (i);
}

static void	fill_tab(char **strs, const char *s, char c)
{
	int	i;
	int	start;
	int	j;

	j = 0;
	i = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			strs[j] = ft_substr(s, start, i - start);
			ft_free(strs, j);
			if (!strs)
				return ;
			j++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (0);
	strs = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	fill_tab(strs, s, c);
	strs[count_words(s, c)] = 0;
	return (strs);
}
