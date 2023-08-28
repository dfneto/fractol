/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:54:18 by davifern          #+#    #+#             */
/*   Updated: 2022/06/18 11:03:57 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * PARAMETERS:
 * s1: The prefix string.
 * s2: The suffix string.
 * RETURN VALUE:
 * The new string.
 * NULL if the allocation fails.
 * DESCRIPTION:
 * Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	str = (char *)malloc(size * sizeof(char) + 1);
	if (!str)
		return (0);
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

/*
* Another waay to iterate over the second string:
	int j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
*/

/*
int main()
{
	char *s1 = "escuela";
	char *s2 = "42";
	char *s3 = ft_strjoin(s1, s2);
	printf("resultado: %s\n", s3);
	return 0;
}
*/
