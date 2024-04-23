/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubengallien <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:52:04 by rubengallien      #+#    #+#             */
/*   Updated: 2023/11/17 15:39:42 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
/*
int main()
{	
	char mot[8] = "bonjour";
	int fd;
	fd = NULL; //open("test.txt", O_RDWR);
	ft_putstr_fd(mot, fd);
	close(fd);
	return (0);
}
*/
