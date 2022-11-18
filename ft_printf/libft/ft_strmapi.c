/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:24:07 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/14 15:36:56 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*mapi;

	index = 0;
	if (!s)
		return (NULL);
	mapi = (char *)malloc((sizeof(char)) * (ft_strlen(s) + 1));
	if (!mapi)
		return (NULL);
	while (s[index])
	{
			mapi[index] = f(index, s[index]);
			index++;
	}
	mapi[index] = '\0';
	return (mapi);
}
