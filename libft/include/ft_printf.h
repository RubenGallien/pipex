/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:21:27 by rgallien          #+#    #+#             */
/*   Updated: 2024/02/03 17:22:14 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_char(int ap);
int	ft_print_nbr(int ap);
int	ft_print_str(char *str);
int	ft_print_hex(unsigned long long nb, char c);
int	ft_print_unbr(unsigned int nb, int fd);

#endif
