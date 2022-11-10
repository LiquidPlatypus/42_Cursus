/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:51:37 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/10 09:33:31 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;

	if (!s1)
		return (NULL);
	trim = (char *)malloc(sizeof(char) * (ft_strlen(s1) - 2));
	if (trim == NULL)
		return (NULL);
	return (trim);
}
