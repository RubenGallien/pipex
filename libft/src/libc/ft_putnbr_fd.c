/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubengallien <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:43:13 by rubengallien      #+#    #+#             */
/*   Updated: 2023/11/11 17:31:01 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			write(fd, "2147483648", 10);
		}
		else
		{
			ft_putnbr_fd(n * (-1), fd);
		}
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
