/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:44:47 by davifern          #+#    #+#             */
/*   Updated: 2022/06/02 11:01:28 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dest_len;
	size_t			src_len;
	unsigned long	i;
	int				j;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	j = dest_len;
	i = 0;
	if (dstsize <= dest_len)
		return (dstsize + src_len);
	while ((i < dstsize - dest_len - 1) && src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dest_len + src_len);
}
