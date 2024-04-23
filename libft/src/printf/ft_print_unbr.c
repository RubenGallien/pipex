/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:00:32 by rgallien          #+#    #+#             */
/*   Updated: 2023/12/13 15:07:01 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_unbr(unsigned int nb, int fd)
{
	int	ln;

	ln = 0;
	if (nb >= 0 && nb < 10)
		ft_print_char(nb + '0');
	else
	{
		ln += ft_print_unbr(nb / 10, fd);
		ft_print_unbr(nb % 10, fd);
	}
	return (ln + 1);
}
