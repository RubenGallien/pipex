/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:48:25 by rgallien          #+#    #+#             */
/*   Updated: 2023/12/13 15:05:07 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	ln;

	if (!str)
		str = "(null)";
	ln = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (ln);
}
