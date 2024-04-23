/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:51:31 by rgallien          #+#    #+#             */
/*   Updated: 2023/11/09 23:03:10 by rubengallien     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main()
{
	int i = 0;
	char mot[8] = "bonjour";
	while(mot[i] != '\0')
	{
		ft_putchar_fd(mot[i], 1);
		i++;
	}
	return (0)
}
*/
