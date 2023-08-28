/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:40:37 by davifern          #+#    #+#             */
/*   Updated: 2022/05/24 09:57:04 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*string;

	i = 0;
	string = (char *)b;
	while (i < len)
	{
		string[i] = c;
		i++;
	}
	return ((void *)string);
}
