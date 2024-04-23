/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:30:49 by rgallien          #+#    #+#             */
/*   Updated: 2023/11/15 15:05:00 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (ptr[i] != (char)c)
	{
		if (ptr[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return (ptr + i);
}
/*
int main()
{
		printf("%s\n", ft_strchr("bonjour", 'z'));
		printf("%s\n", strchr("bonjour", 'z'));
		return (0);
}
*/
