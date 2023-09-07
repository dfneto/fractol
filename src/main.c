/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:09:39 by david             #+#    #+#             */
/*   Updated: 2023/09/07 18:31:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// Para eu usar o include sem o path, ou seja, ao invés de usar 
// #include "../deps/ft_printf/ft_printf.h" eu tenho que compilar assim:
// gcc -Ideps/ft_printf src/main.c -Ldeps/ft_printf -lftprintf && ./a.out
// E se eu tenho #include "deps/ft_printf/ft_printf.h" eu compilo:
// gcc deps/ft_printf/libftprintf.a src/main.c && ./a.out
// Em ambos casos eu compilei estando na raiz do projeto.

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    ft_printf("--------------------------\n");
    ft_printf("SUCESSO DE MAKE PORRA!!!\n");
    ft_printf("--------------------------\n");
}