/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:35:02 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/09 09:43:07 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *s1)
{
	int		x;
	char	*s2;

	x = 0;
	s2 = (char *)malloc(sizeof(s1));
	if (s2 == NULL)
		return (NULL);
	while (s1[x++])
		s2[x] = s1[x];
	return (*s2);
}
