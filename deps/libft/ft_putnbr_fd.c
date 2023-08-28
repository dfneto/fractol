/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:27:29 by davifern          #+#    #+#             */
/*   Updated: 2022/06/18 10:49:20 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * Parameters: 
 * n:			The integer to output.
 * fd:			The file descriptor on which to write. 
 * Return:		None
 * Description: Outputs the integer ’n’ to the given file descriptor.
 */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	a = 0;
	if (n < 0)
	{
		write(fd, &"-", 1);
		n = n * (-1);
	}
	if (n == -2147483648)
		write(fd, &"2147483648", 10);
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		a = n + 48;
		write(fd, &a, 1);
	}
}
