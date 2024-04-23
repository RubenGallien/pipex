/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:18:22 by rgallien          #+#    #+#             */
/*   Updated: 2023/11/17 15:41:13 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;
	int		len_needle;

	hay = (char *)haystack;
	i = 0;
	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return (hay);
	if (len == 0)
		return (NULL);
	while (hay[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (!needle[j + 1])
				return (hay + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int main()
{
	const char *str = "bonjour";
	const char *str2 = "ou";
	printf("mine : %s\n", ft_strnstr(str, str2, 6));

	const char *str3 = "bonjour";
	const char *str4 = "ou";
	printf("real : %s\n", strnstr(str3, str4, 6));

	return (0);
}
*/
