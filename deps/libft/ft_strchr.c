/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:06:57 by davifern          #+#    #+#             */
/*   Updated: 2023/08/28 10:13:08 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *s, int c)
{
	char	c_;

	c_ = (char) c;
	while (*s != c_ && *s)
		s++;
	if (*s == c_)
		return (s);
	else
		return (0);
}
// #include <stdio.h>
// int main()
// {
// 	char *str = "Hola david, que tal?";

// 	printf("%s\n", ft_strchr(str, 'd')); //david, que tal?
// }
