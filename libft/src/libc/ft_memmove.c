/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:26:33 by rgallien          #+#    #+#             */
/*   Updated: 2023/11/12 23:53:15 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t						i;
	const unsigned char			*source;
	unsigned char				*destination;

	i = 0;
	destination = (unsigned char *) dest;
	source = (unsigned char *) src;
	if (destination == NULL && source == NULL)
		return (NULL);
	if (destination > source)
	{
		while (n-- > 0)
		{
			destination[n] = source[n];
		}
	}
	else
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dest);
}
