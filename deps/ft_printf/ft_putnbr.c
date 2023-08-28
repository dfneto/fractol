/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:41:09 by davifern          #+#    #+#             */
/*   Updated: 2023/08/28 11:09:47 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	write_num_dealing_with_slash_zero(char *num, int length)
{
	if ((*num) != '\0')
	{
		if (write(1, num, 1) == -1)
			return (-1);
	}
	return (length + 1);
}

int	deal_with_negative_number(int *nb, int length)
{
	if ((*nb) < 0)
	{
		(*nb) = -(*nb);
		length++;
		if (write(1, "-", 1) == -1)
			return (-1);
	}
	return (length);
}

int	ft_putnbr(int nb)
{
	char	num;
	int		length;
	int		a;

	num = 0;
	length = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	length = deal_with_negative_number(&nb, length);
	if (length == -1)
		return (-1);
	if (nb <= 9)
		num = nb + '0';
	else
	{
		a = ft_putnbr(nb / 10);
		if (a == -1)
			return (-1);
		length = length + a;
		if (ft_putnbr(nb % 10) == -1)
			return (-1);
	}
	return (write_num_dealing_with_slash_zero(&num, length));
}

/*
int main()
{
	int a = ft_putnbr(-12);
	printf("\n\n\nTamanho de digitos del numero: %i\n", a);
	return (0);
}
*/
/*
 * I just print if num_length is diferent of '\0' to
 * don't print question mark (check in python
 * tutor without this condition).
 */
