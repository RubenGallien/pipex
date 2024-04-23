/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:13:56 by rgallien          #+#    #+#             */
/*   Updated: 2023/11/17 12:51:18 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	itoa_second(char *str, unsigned int nb, int len, int signe)
{
	int	i;

	i = 1;
	while (nb >= 1)
	{
		str[len - i] = (nb % 10) + 48;
		nb /= 10;
		i++;
	}
	if (signe == -1)
		*str = '-';
}

static int	len_string(int n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	nb;
	char			*str;
	int				signe;

	signe = 1;
	nb = 1;
	len = len_string(n);
	if (n < 0)
		signe = -1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		n *= -1;
	nb = n;
	if (nb == 0)
		*str = '0';
	nb = n;
	itoa_second(str, nb, len, signe);
	str[len] = 0;
	return (str);
}
