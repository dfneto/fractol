/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:40:49 by davifern          #+#    #+#             */
/*   Updated: 2023/09/20 17:41:25 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	define_color_2(int	i)
{
	if (i == 8)
        return (BLUE_0);
    else if (i == 9)
        return (LIGHTEST_BLUE);
    else if (i == 10)
        return (LIGHTEST_YELLOW);
    else if (i == 11)
        return (LIGHT_YELLOW);
    else if (i == 12)
        return (DIRTY_YELLOW);
    else if (i == 13)
        return (BROWN_0);
    else if (i == 14)
        return (BROWN_1);
    else
        return (BROWN_2);
}

int	define_color(int number_of_iterations)
{
	int	i;

	i = number_of_iterations % 16;
	if (i == 0)
        return (BROWN_3);
    else if (i == 1)
        return (DARK_VIOLET);
    else if (i == 2)
        return (DARKEST_BLUE);
    else if (i == 3)
        return (BLUE_5);
    else if (i == 4)
        return (BLUE_4);
    else if (i == 5)
        return (BLUE_3);
    else if (i == 6)
        return (BLUE_2);
    else if (i == 7)
        return (BLUE_1);
    else 
		return (define_color_2(i));
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}