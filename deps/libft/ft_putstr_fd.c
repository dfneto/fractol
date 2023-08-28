/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:49:04 by davifern          #+#    #+#             */
/*   Updated: 2022/06/14 16:03:15 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * Parameters: 
 * s:			The string to output. 
 * fd:			The file descriptor on which to write. 
 * Return:		None
 * Description: Outputs the string ’s’ to the given file descriptor.
 */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
	}
}
