/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:26:20 by rgallien          #+#    #+#             */
/*   Updated: 2023/12/13 15:06:25 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	check_letter(const char format, va_list ap)
{
	int	i;

	i = 0;
	if (format == 'c')
		i = ft_print_char(va_arg(ap, int));
	else if (format == 'd' || format == 'i')
		i = ft_print_nbr(va_arg(ap, int));
	else if (format == 's')
		i = ft_print_str(va_arg(ap, char *));
	else if (format == 'X' || format == 'x')
		i = ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == 'p')
		i = ft_print_hex((unsigned long long)va_arg(ap, void *), format);
	else if (format == 'u')
		i = ft_print_unbr(va_arg(ap, unsigned int), 1);
	else if (format == '%')
		i = write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i += check_letter(*format, ap);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			i++;
		}
		format++;
	}
	va_end(ap);
	return (i);
}
