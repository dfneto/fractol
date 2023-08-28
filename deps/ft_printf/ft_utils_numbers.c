/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:09:47 by davifern          #+#    #+#             */
/*   Updated: 2023/01/30 20:27:30 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	print_int(va_list arg_ptr)
{
	int	int_value;

	int_value = va_arg(arg_ptr, int);
	return (ft_putnbr(int_value));
}

int	print_unsigned_int(va_list arg_ptr)
{
	unsigned int	unsigned_int_value;

	unsigned_int_value = va_arg(arg_ptr, unsigned int);
	return (ft_putnbr_uint(unsigned_int_value));
}

int	print_hexadecimal(va_list arg_ptr, char x_or_X)
{
	unsigned int	value;

	value = va_arg(arg_ptr, unsigned int);
	return (convert_uint_to_hexadecimal_and_write(value, x_or_X));
}

int	print_pointer(va_list arg_ptr)
{
	unsigned long long	p;

	p = va_arg(arg_ptr, unsigned long long);
	if (write(1, &"0x", 2) == -1)
		return (-1);
	return (convert_ulonglong_to_hexadecimal(p) + 2);
}
