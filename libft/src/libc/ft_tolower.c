/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:20:23 by rgallien          #+#    #+#             */
/*   Updated: 2023/11/10 17:50:30 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	lettre;

	lettre = c;
	if (lettre >= 65 && lettre <= 90)
	{
		return (lettre + 32);
	}
	return (lettre);
}
/*
int main()
{
		printf("%c", ft_tolower('C'));
		return (0);
}
*/
