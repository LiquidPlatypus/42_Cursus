/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:20:28 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/10 09:33:58 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**splited_str;

	index = 0;
	if (!s)
		return (NULL);
	splited_str = (char **)malloc(sizeof(char) * ft_strlen(s));
	if (splited_str == NULL)
		return (NULL);
}
