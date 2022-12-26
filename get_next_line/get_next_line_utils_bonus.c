/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:02:17 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/26 11:29:26 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_sstrlen(const char *s)
{
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l] != '\0')
		++l;
	return (l);
}

char	*ft_find_nl(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (str);
			++str;
		}
	}
	return (NULL);
}

static t_buf_list	*ft_create_lst(int fd)
{
	t_buf_list	*lst;

	lst = malloc(1 * sizeof(t_buf_list));
	if (!lst)
		return (NULL);
	lst->fd = fd;
	lst->left = NULL;
	lst->next = NULL;
	return (lst);
}

t_buf_list	*ft_find_or_create_lst(t_buf_list **list, int fd)
{
	t_buf_list	*cur_lst;

	if (*list == NULL)
	{
		*list = ft_create_lst(fd);
		return (*list);
	}
	cur_lst = *list;
	while (cur_lst->fd != fd)
	{
		if (cur_lst->next == NULL)
			cur_lst->next = ft_create_lst(fd);
		cur_lst = cur_lst->next;
		if (cur_lst == NULL)
			return (NULL);
	}
	return (cur_lst);
}

void	ft_remove_lst_item(t_buf_list **list, t_buf_list *item)
{
	t_buf_list	*cur_lst;

	if (*list == item)
	{
		*list = item->next;
	}
	else
	{
		cur_lst = *list;
		while (cur_lst->next != item)
			cur_lst = cur_lst->next;
		cur_lst->next = item->next;
	}
	free(item);
}
