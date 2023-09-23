/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:36:12 by davifern          #+#    #+#             */
/*   Updated: 2023/09/23 14:31:36 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_negative(char a)
{
	if (a == '-')
		return (-1);
	return (1);
}

int	has_positive_signal(char a)
{
	if (a == '+')
		return (1);
	return (0);
}

float	ft_atof(const char *str)
{
	int		i;
	int		numbers_after_comma;
	float	result;

	result = 0;
	i = 0;
	numbers_after_comma = 0;
	if (is_negative(str[i]) == -1 || has_positive_signal(str[i]))
		i++;
	while ((str[i] >= 48 && str[i] <= 57) || str[i] == '.')
	{
		if (str[i] == '.')
		{
			numbers_after_comma = 1;
			i++;
		}
		result = result * 10 + (str[i] - 48);
		if (numbers_after_comma >= 1)
			numbers_after_comma = numbers_after_comma * 10;
		i++;
	}
	return (result * is_negative(str[0]) / numbers_after_comma);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%.6f\n", ft_atof("-100.432567"));
	printf("%.6f\n", ft_atof("100.432567"));
	printf("%.6f\n", ft_atof("0.432567"));
	printf("%.6f\n", ft_atof("-1.432567"));
	return (0);
}
*/

/* ORIGINAL METHOD
float	ft_atof(const char *str)
{
	int		i;
	int		numbers_after_comma;
	float	result;
	float	signal;

	result = 0;
	signal = 1;
	i = 0;
	numbers_after_comma = 0;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57) || str[i] == '.')
	{
		if (str[i] == '.')
		{
			numbers_after_comma = 1;
			i++;
		}
		result = result * 10 + (str[i] - 48);
		if (numbers_after_comma >= 1)
			numbers_after_comma = numbers_after_comma * 10;
		i++;
	}
	return (result * signal / numbers_after_comma);
}
*/