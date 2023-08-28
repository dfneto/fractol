/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:25:29 by davifern          #+#    #+#             */
/*   Updated: 2022/06/08 18:43:48 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_;
	unsigned char	*s_;
	unsigned long	i;

	c_ = (unsigned char) c;
	s_ = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (s_[i] == c_)
			return ((void *)&s_[i]);
		i++;
	}
	return (0);
}
