/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:27:34 by davifern          #+#    #+#             */
/*   Updated: 2022/06/18 10:44:32 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len_num(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		signal;

	signal = 1;
	len = get_len_num(n);
	num = (char *)malloc(len * sizeof(char) + 1);
	if (!num)
		return (0);
	num[len] = '\0';
	len--;
	if (n < 0)
		signal = -1;
	while (len >= 0)
	{
		num[len] = (n % 10) * signal + '0';
		n = n / 10;
		len--;
	}
	if (signal < 0)
		num[0] = '-';
	return (num);
}
/*
int main()
{
	char *ret = ft_itoa(-2147483647);
	printf("ret: %s\n", ret);
//	printf("%d\n", -123 % 10 + 48);
//	printf("n resto 10: %d\n", 423 % 10);
	return (0);
}
*/
