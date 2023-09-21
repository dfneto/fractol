/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:36:12 by davifern          #+#    #+#             */
/*   Updated: 2023/09/21 22:51:50 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *str)
{
	int		i;
	double	result;
	double	signal;

	result = 0;
	signal = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		// if (str[i] == '.')
		// 	i++;
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * signal);
}

int main()
{

	return 0;
}
