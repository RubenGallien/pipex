/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:17:01 by rgallien          #+#    #+#             */
/*   Updated: 2023/12/13 15:04:01 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_hex2(unsigned long long nb, char *base)
{
	int		i;
	char	c;

	i = 0;
	if (nb > 15)
		i += ft_print_hex2(nb / 16, base);
	c = base[nb % 16];
	write(1, &c, 1);
	return (i + 1);
}

int	ft_print_hex(unsigned long long nb, char c)
{
	int	i;

	i = 0;
	if (c == 'x' || c == 'p')
	{
		if (c == 'p')
		{
			if (!nb)
				return (write(1, "(nil)", 5));
			i += write(1, "0x", 2);
		}
		i += ft_print_hex2(nb, "0123456789abcdef");
	}
	else if (c == 'X')
		i = ft_print_hex2(nb, "0123456789ABCDEF");
	return (i);
}
