/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbournon <tbournon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:06:26 by tbournon          #+#    #+#             */
/*   Updated: 2022/12/04 11:06:26 by tbournon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Uses read() to add characters to the stash

void	read_and_stash(int fd, t_list **stash, int *reader)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return ;
	while (!found_newline(*stash) && *reader != 0)
	{
		*reader = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*stash == NULL && *reader == 0 || *reader == -1))
		{
			free(buffer);
			return ;
		}
		buffer[*reader] = '\0';
	}
}

// Adds the content of our buffer to the end of our stash

void	add_to_stash()
{

}

/* Extracts all characters from our stash and stores them in out line.
   Stoping after the first \n it encouters */

void	extract_line()
{

}

/* After extracting the line that was read, we don't need those characters anymore.
   This function clears the stash so only the characters that have not been returned at
   the end of get_next_line() remain in our static stash. */

void	clean_stash()
{

}
