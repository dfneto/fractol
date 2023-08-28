/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:08:50 by davifern          #+#    #+#             */
/*   Updated: 2023/08/28 10:12:42 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * PARAMETERS:
 * s1: The string to be trimmed.
 * set: The reference set of characters to trim.
 * RETURN VALUE:
 * The trimmed string.
 * NULL if the allocation fails.
 * DESCRIPTION:
 * Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
 * specified in ’set’ removed from the beginning and the end of the string.
 */

#include "libft.h"

int	get_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				break ;
			}
			else
				j++;
		}
		if (set[j] == '\0')
			break ;
	}
	return (i);
}

int	get_end(char const *s1, char const *set, int start)
{
	int	len;
	int	j;

	j = 0;
	len = ft_strlen(s1) - 1;
	while (len > start)
	{
		j = 0;
		while (set[j])
		{
			if (s1[len] == set[j])
			{
				len--;
				break ;
			}
			else
				j++;
		}
		if (set[j] == '\0')
			break ;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		i;
	int		end;

	start = get_start(s1, set);
	end = get_end(s1, set, start);
	str = (char *)malloc((end - start + 1) * sizeof(char) + 1);
	if (!str)
		return (0);
	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
int main()
{
	char *s1 = "ltltltltltltorem ipsum dolor sit ametltlltltltlt";
	char *set = "lt";
	char *ret = ft_strtrim(s1, set); //orem ipsum dolor sit ame

	// char *s1 = "ltltltltltltorem ipsum dolor sit ametltlltltltlt";
	// char *set = "lt";
	// char *ret = ft_strtrim(s1, set); //orem ipsum dolor sit ame


	// char s1[] = " lorem \n ipsum \t dolor \n sit \t amet ";
	// char *ret = ft_strtrim(s1, " ");

	// char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t Please\n Trim me !\n 
	  \n \n \t\t\n  ";
	// char *s1 = "Hello \t  Please\n Trim me !";
	// char *ret = ft_strtrim(s1, " \n\t");

	printf("%s\n", s1);
	printf("New string:\n");
	printf("%s\n", ret);
	return (0);
}
*/
