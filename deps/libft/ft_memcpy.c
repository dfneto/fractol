/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:41:41 by davifern          #+#    #+#             */
/*   Updated: 2022/05/31 12:42:48 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*string_dst;
	char	*string_src;

	if (dst == 0 && src == 0)
		return (dst);
	string_dst = (char *)dst;
	string_src = (char *)src;
	i = 0;
	while (i < n)
	{
		string_dst[i] = string_src[i];
		i++;
	}
	return ((void *)string_dst);
}
