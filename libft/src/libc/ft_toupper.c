/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:11:38 by rgallien          #+#    #+#             */
/*   Updated: 2023/11/10 17:50:16 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	lettre;

	lettre = c;
	if (lettre >= 97 && lettre <= 122)
	{
		return (lettre - 32);
	}
	return (lettre);
}
/*
int main()
{
		printf("%c", ft_toupper('c'));
		return (0);
}
*/
