/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:37:18 by davifern          #+#    #+#             */
/*   Updated: 2022/06/03 09:17:11 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	c_;
	int		len;

	c_ = (char) c;
	len = ft_strlen(s);
	while (s[len] != c_ && len > 0)
		len--;
	if (s[len] == c_)
	{
		return (&s[len]);
	}
	else
	{
		return (0);
	}
}
