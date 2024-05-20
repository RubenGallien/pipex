/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:44:53 by rgallien          #+#    #+#             */
/*   Updated: 2024/05/20 16:02:00 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = ft_strlen(s);
	ptr = (char *)s;
	while (i >= 0)
	{
		if (ptr[i] == (char)c)
		{
			return (ptr + i);
		}
		i--;
	}
	return (NULL);
}
// int main()
// {
// 		printf("%s\n", ft_strrchr("bonjour", 'o'));
// 		printf("%s\n", strrchr("bonjour", 'o'));
// 		return (0);
// }
