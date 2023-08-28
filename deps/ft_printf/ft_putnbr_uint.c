/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:25:30 by davifern          #+#    #+#             */
/*   Updated: 2023/01/31 15:46:41 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putnbr_uint(unsigned int nb)
{
	char	num;
	int		length;
	int		ret;

	num = 0;
	length = 0;
	if (nb <= 9)
		num = nb + '0';
	else
	{
		ret = ft_putnbr_uint(nb / 10);
		if (ret == -1)
			return (-1);
		length = length + ret;
		if (ft_putnbr_uint(nb % 10) == -1)
			return (-1);
	}
	if (num != '\0')
	{
		if (write(1, &num, 1) == -1)
			return (-1);
	}
	return (length + 1);
}
/*
 * I just print if num_length is diferent of '\0' to
 * in ft_unsigned_int and ft_putnbr
 * don't print question mark (check in python
 * tutor without this condition).
 */
