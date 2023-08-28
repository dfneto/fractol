/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:11:37 by davifern          #+#    #+#             */
/*   Updated: 2022/06/18 10:51:21 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * PARAMETERS:
 * s: The string on which to iterate.
 * f: The function to apply to each character.
 * RETURN VALUE:
 * None
 * DESCRIPTION:
 *  Applies the function ’f’ on each character of the string passed as argument,
 *   passing its index as first argument. Each character is passed by address to 
 *   ’f’ to be modified if necessary.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
