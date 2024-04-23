/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallien <rgallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:49:39 by rgallien          #+#    #+#             */
/*   Updated: 2024/03/05 23:09:32 by rgallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*get_next_line(int fd);
char	*read_fd(char	*stash, int fd);
int		found_return(char *stash, char c);
char	*ft_join(char *stash, char *buffer);
int		len_str(char *str);
char	*fill_ligne(char	*tmp);
char	*dup_str(char *src);
void	shift_stash(char	*stash);

#endif
