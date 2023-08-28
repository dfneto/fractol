/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:41:49 by davifern          #+#    #+#             */
/*   Updated: 2022/06/18 16:55:50 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * PARAMETERS:
 * s: The string to be split.
 * c: The delimiter character.
 * RETURN VALUE:
 * The array of new strings resulting from the split. 
 * NULL if the allocation fails.
 * DESCRIPTION:
 * Allocates (with malloc(3)) and returns an array of strings obtained 
 * by splitting ’s’ using the character ’c’ as a delimiter. The array
 * must end with a NULL pointer.
 */

#include "libft.h"

int	get_number_of_words(char const *s, char c)
{
	int	num_words;
	int	count;

	num_words = 0;
	count = 0;
	while (s[count])
	{
		if (s[count] != c && (s[count + 1] == c || s[count + 1] == '\0'))
			num_words++;
		count++;
	}
	return (num_words);
}

void	free_memory(char **str, int i)
{
	int	count;

	count = 0;
	while (count < i)
	{
		free(str[count]);
		count++;
	}
	free(str);
}

int	is_start_the_word(char const *s, int delimiter, int count)
{
	int	is_start_the_word;

	is_start_the_word = (s[count] != delimiter
			&& ((count > 0 && s[count - 1] == delimiter)
				|| (count == 0 && s[count] != '\0')));
	return (is_start_the_word);
}

char	**create_array_with_splitted_words(char const *s, char c, char **str)
{
	int		i;
	int		count;
	int		start;

	start = 0;
	i = 0;
	count = 0;
	while (s[count])
	{
		if (is_start_the_word(s, c, count))
			start = count;
		if (s[count] != c && (s[count + 1] == c || s[count + 1] == '\0'))
		{
			str[i] = ft_substr(s, start, count - start + 1);
			if (str[i] == NULL)
			{
				free_memory(str, i);
				return (0);
			}
			i++;
		}
		count++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	str = (char **)malloc((get_number_of_words(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	str = create_array_with_splitted_words(s, c, str);
	return (str);
}

/*
int main()
{
	int i = 0;
//	char **str = ft_split("hello!", ' ');
//	char **str = ft_split("xxxxxxxxhello!", 'x');
	char **str = ft_split("hello world", ' ');
//	char **str = ft_split("h", 'h');
	
	while (str[i] != 0)
	{
		printf("%s\n", str[i]);
		i++;
	}
	
	return (0);
}
*/
