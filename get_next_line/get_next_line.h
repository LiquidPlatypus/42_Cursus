/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:02:16 by lsinke        #+#    #+#                 */
/*   Updated: 2022/04/19 18:02:16 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>

char	*get_next_line(int fd);

/**
 * Null safe version of strlen. Returns 0 if the string is NULL
 */
size_t	ft_strlen(const char *s);
/**
 * Finds a newline character in the string, and returns a pointer to it
 * returns NULL if no newline was found
 */
char	*find_newline(char *str);

#endif