/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:13:04 by davifern          #+#    #+#             */
/*   Updated: 2023/01/30 20:03:35 by davifern         ###   ########.fr       */
/*                                                                            */
/*  source: https://nxmnpg.lemoda.net/3/va_start                              */
/*  d só é diferente do i no scanf                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	check_case(char a, va_list arg_ptr, int *i)
{
	int	ret;

	ret = 0;
	if (a == 'c')
		return (print_char(arg_ptr, i));
	if (a == 's')
		ret = print_string(arg_ptr);
	else if (a == 'i' || a == 'd')
		ret = print_int(arg_ptr);
	else if (a == 'u')
		ret = print_unsigned_int(arg_ptr);
	else if (a == 'x' || a == 'X')
		ret = print_hexadecimal(arg_ptr, a);
	else if (a == 'p')
		ret = print_pointer(arg_ptr);
	(*i)++;
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		string_size;
	va_list	arg_ptr;
	int		ret;

	string_size = 0;
	i = 0;
	va_start(arg_ptr, s);
	while (s[i])
	{
		if (s[i] != '%' || s[i + 1] == '%')
			ret = print_normal_or_porcent(s[i], &i);
		else
			ret = check_case(s[i + 1], arg_ptr, &i);
		if (ret <= -1)
			return (-1);
		string_size += ret;
		i++;
	}
	va_end(arg_ptr);
	return (string_size);
}

// #include <stdio.h>
// int main()
// {
// 	// Testing %s
// 	char *str = "hola kluwekuhr we;lr w;eiruew ri";
// 	ft_printf("%s\n", str);
// 	// int ret_printf;
// 	// ret_printf = printf("%x", -10);
// 	// printf("-->%i\n", ret_printf);
// 	// ret_printf = ft_printf("%x", -10);
// 	// printf("-->%i\n", ret_printf);
// }
