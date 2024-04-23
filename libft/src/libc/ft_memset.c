/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:47:23 by rgallien          #+#    #+#             */
/*   Updated: 2023/11/13 17:33:01 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
/*
int main ()
{
  int str[] = {54, 85, 20, 63, 21};
  printf("%d\n", str[0]);
  memset(str, 1, 20);
  printf("%d\n", str[0]);
  int str2[] = {54, 85, 20, 63, 21};  
  ft_memset(str2, 1, 20);
  printf("%d\n", str2[0]);
  return 0;
}
*/
