/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:33:36 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/08 12:10:45 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int			index;

	index = 0;
	while (s[index] != (unsigned char)c && s[index] != '\0')
		index++;
	if (s[index] == (unsigned char)c)
		return ((char *)&s[index]);
	else
		return (NULL);
}
