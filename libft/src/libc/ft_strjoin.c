/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:01:53 by rgallien          #+#    #+#             */
/*   Updated: 2024/03/12 17:09:13 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		total;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	s3 = malloc(sizeof(char) * (total + 1));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s3[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	free(s1);
	s3[total] = '\0';
	return (s3);
}
/*
int main()
{
		printf("\nTest de ft_strjoin :\n");
		printf("abcdef : %s\n",	ft_strjoin("abc", "def"));
		printf("abc : %s\n", ft_strjoin("", "abc"));
		printf("abc : %s\n", ft_strjoin("abc", ""));
		printf("'' : %s\n", ft_strjoin("", ""));
}
*/
