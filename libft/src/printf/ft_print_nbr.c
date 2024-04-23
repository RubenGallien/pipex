/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:14:29 by rgallien          #+#    #+#             */
/*   Updated: 2023/12/13 15:02:29 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_nbr(int ap)
{
	int		ln;
	char	*str;

	str = ft_itoa(ap);
	ft_putstr_fd(str, 1);
	ln = ft_strlen(str);
	free(str);
	return (ln);
}
