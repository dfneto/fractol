/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:46:52 by davifern          #+#    #+#             */
/*   Updated: 2022/06/18 10:46:06 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	int				diff;
	unsigned char	*s1_;
	unsigned char	*s2_;

	s1_ = (unsigned char *) s1;
	s2_ = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		diff = s1_[i] - s2_[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}
