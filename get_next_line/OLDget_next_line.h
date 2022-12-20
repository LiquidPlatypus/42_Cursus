/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLDget_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:08:09 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/20 12:59:37 by tbournon         ###   ########.fr       */
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

char	*get_next_line(int fd);

// get_next_line_utils.c

int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);

#endif