/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:37:08 by davifern          #+#    #+#             */
/*   Updated: 2023/08/28 11:03:45 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *s, ...);
int		print_normal_or_porcent(char a, int *i);
int		ft_putnbr(int n);
int		ft_putnbr_uint(unsigned int n);
size_t	get_len(char *s);
int		print_char(va_list arg_ptr, int *i);
int		print_int(va_list arg_ptr);
int		print_string(va_list arg_ptr);
int		convert_ulonglong_to_hexadecimal(unsigned long long value);
int		print_pointer(va_list arg_ptr);
int		print_unsigned_int(va_list arg_ptr);
int		convert_uint_to_hexadecimal_and_write(unsigned int value, char x_or_X);
int		print_hexadecimal(va_list arg_ptr, char x_or_X);

#endif