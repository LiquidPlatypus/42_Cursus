/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:35:02 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/09 10:03:36 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	int		x;
	char	*s2;

	x = ft_strlen(s1) + 1;
	s2 = malloc(x);
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s1, x);
	return (s2);
}
