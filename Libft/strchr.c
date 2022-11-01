/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:33:36 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/01 16:04:19 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int			index;
	
	index = 0;
	while (s[index] != c && s[index] != '\0')
		index++;
	if (s[index] == c)
		return ((char *)&s[index]);
	else
		return (NULL);
}
