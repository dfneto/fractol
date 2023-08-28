/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:31:56 by davifern          #+#    #+#             */
/*   Updated: 2022/05/31 12:37:16 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	source = (char *)src;
	dest = (char *)dst;
	if (dst > src)
	{
		while (len--)
			dest[len] = source[len];
	}
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return ((void *)dest);
}
