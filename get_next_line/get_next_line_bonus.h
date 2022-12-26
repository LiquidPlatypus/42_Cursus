/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:02:16 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/26 11:29:25 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_buf_list
{
	int					fd;
	char				*left;
	struct s_buf_list	*next;
}	t_buf_list;

char		*get_next_line(int fd);

/**
 * Null safe version of strlen. Returns 0 if the string is NULL
 */
size_t		ft_sstrlen(const char *s);
/**
 * Finds a newline character in the string, and returns a pointer to it
 * returns NULL if no newline was found
 */
char		*ft_find_nl(char *str);
/**
 * Find a list lstect with the correct fd in the list
 * create one if not found
 */
t_buf_list	*ft_find_or_create_lst(t_buf_list **list, int fd);
/**
 * Removes a list item from the list, setting list to NULL if item was first
 */
void		ft_remove_lst_item(t_buf_list **list, t_buf_list *item);

#endif