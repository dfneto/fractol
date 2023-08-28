/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:57:40 by davifern          #+#    #+#             */
/*   Updated: 2023/01/30 20:32:01 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_ulonglong_to_hexadecimal(unsigned long long value)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (value < 10)
		return (ft_putnbr(value));
	if (value >= 10 && value < 16)
	{
		value += 87;
		return (write(1, &value, 1));
	}
	a += convert_ulonglong_to_hexadecimal(value / 16);
	b += convert_ulonglong_to_hexadecimal(value % 16);
	return (a + b);
}

int	write_value_according_to_x(unsigned int value, char x_or_X)
{
	int	c;

	c = 0;
	if (x_or_X == 'x')
		c = value + 87;
	else
		c = value + 55;
	return (write(1, &c, 1));
}

int	convert_uint_to_hexadecimal_and_write(unsigned int value, char x_or_X)
{
	int		a;
	int		b;
	int		temp;

	a = 0;
	b = 0;
	if (value < 10)
		return (ft_putnbr(value));
	if (value >= 10 && value < 16)
		return (write_value_according_to_x(value, x_or_X));
	temp = convert_uint_to_hexadecimal_and_write(value / 16, x_or_X);
	if (temp == -1)
		return (-1);
	a += temp;
	temp = convert_uint_to_hexadecimal_and_write(value % 16, x_or_X);
	if (temp == -1)
		return (-1);
	b += temp;
	return (a + b);
}
