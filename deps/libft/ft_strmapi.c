/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:36:19 by davifern          #+#    #+#             */
/*   Updated: 2022/06/18 10:52:16 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * PARAMETERS:
 * s: The string on which to iterate.
 * f: The function to apply to each character.
 * RETURN VALUE:
 * The string created from the successive applications of ’f’.
 * Returns NULL if the allocation fails.
 * DESCRIPTION:
 * Applies the function ’f’ to each character of the string ’s’, and passing 
 * its index as first argument to create a new string (with malloc(3))
 * resulting from successive applications of ’f’.
 */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!result)
		return (0);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
