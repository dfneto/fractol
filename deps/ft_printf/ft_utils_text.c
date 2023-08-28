/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:27:46 by davifern          #+#    #+#             */
/*   Updated: 2023/08/28 11:10:29 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_normal_or_porcent(char a, int *i)
{
	if (write(1, &a, 1) == -1)
		return (-1);
	if (a == '%')
		(*i)++;
	return (1);
}

int	print_char(va_list arg_ptr, int *i)
{
	char	ptr;

	ptr = va_arg(arg_ptr, int);
	if (write(1, &ptr, 1) == -1)
		return (-1);
	(*i)++;
	return (1);
}

//TODO: verificar se devo encerrar a cadeia de string com \0
int	print_string(va_list arg_ptr)
{
	char	*string;

	string = va_arg(arg_ptr, char *);
	if (string == NULL)
		return (write(1, "(null)", 6));
	return (write(1, string, get_len(string)));
}
