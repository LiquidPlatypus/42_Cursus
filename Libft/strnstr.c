/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:57:42 by tbournon          #+#    #+#             */
/*   Updated: 2022/11/02 13:13:55 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	index1;
	int	index2;

	index1 = 0;
	index2 = 0;
	if (needle[index2] == '\0')
		return ((char *)haystack);
	while (haystack[index1] != '\0')
	{
		while ((haystack[index1 + index2] == needle[index2])
			&& haystack[index1 + index2] != '\0' && len > 0)
		{
			index2++;
			len--;
		}
		if (needle[index2] == '\0')
			return ((char *)haystack + index1);
		index1++;
		index2 = 0;
	}
	return (NULL);
}

/* int main()
{
	char str1[] = "ceci est un test";
	char str2[] = "est";

	printf("%s", ft_strnstr(str1, str2, 10));

	return 0;
} */