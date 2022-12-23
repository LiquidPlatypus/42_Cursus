/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:02:16 by lsinke            #+#    #+#             */
/*   Updated: 2022/12/23 15:56:21 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

/**
 * Join s1 and s2, making a copy of s2 if s1 is null. Always free s1.
 *
 * Takes the lengths of s1 and s2 as additional args to improve performance
 *
 * @return NULL if malloc fails, otherwise a freshly malloced string
 */
char	*ft_strjoin(char *s1, const char *s2, size_t s1_len, size_t s2_len);
/**
 * Null safe version of strlen. Returns 0 if the string is NULL
 */
size_t	ft_sstrlen(const char *s);
/**
 * Finds a newline character in the string, and returns a pointer to it
 * returns NULL if no newline was found
 */
char	*ft_find_nl(char *str);

#endif