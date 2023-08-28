/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:46:46 by davifern          #+#    #+#             */
/*   Updated: 2022/06/14 15:48:12 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
 * Parameters: 
 * c: 			The character to output.
 * fd:			The file descriptor on which to write. 
 * Return:		None
 * Description: Outputs the character ’c’ to the given file descriptor.
 */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
