/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:58:04 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/17 13:02:39 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*element;
	void	*buffer;

	newlst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		buffer = f(lst->content);
		element = ft_lstnew(buffer);
		if (!element)
		{
			free(buffer);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, element);
		lst = lst->next;
	}
	return (newlst);
}
