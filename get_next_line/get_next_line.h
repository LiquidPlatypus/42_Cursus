/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:24:28 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/20 16:26:32 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// get_next_line.c

void	*ft_freestr(char *left_str, char *buffer);
char	*get_next_line(int fd);

// get_next_line_utils.c

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_stack_line(char *left_str);
char	*ft_left(char *left_str);

#endif