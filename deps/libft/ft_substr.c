/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:39:28 by davifern          #+#    #+#             */
/*   Updated: 2023/08/28 10:17:20 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * s: The string from which to create the substring. 
 * start: The start index of the substring in the string ’s’.
 * len: The maximum length of the substring.
 *
 */

#include "libft.h"

/*
* ft_get_size goal is to define the real size of the substring
* dealing with values of len that would generate errors.
* 1st case: "error"
* 2nd case: if the len of substring is smaler than the current string 
* so use len
* 3rd case: if len is bigger than s_length or if start + len is bigger
* than s_length, just copy from start to the end.
*/
size_t	ft_get_size(char const *s, unsigned int start, size_t len)
{
	size_t	s_length;

	s_length = ft_strlen(s);
	if (start >= s_length)
		return (0);
	if (s_length >= len)
		return (len);
	else
		return (s_length - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	size;

	size = ft_get_size(s, start, len);
	substr = (char *)malloc(size * sizeof(char) + 1);
	if (substr == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		substr[0] = '\0';
		return (substr);
	}
	i = 0;
	while (i < size)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
// #include <stdio.h>
// int main()
// {
// 	char *str = "hola david, que tal?";
// 	printf("String: %s\n", str);
// 	printf("Substring: %s", ft_substr(str, 12, 9));
// }
