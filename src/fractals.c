/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:31:19 by davifern          #+#    #+#             */
/*   Updated: 2023/09/23 13:03:42 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Para eu usar o include sem o path, ou seja, ao invés de usar 
* #include "../deps/ft_printf/ft_printf.h" eu tenho que compilar assim:
* gcc -Ideps/ft_printf src/main.c -Ldeps/ft_printf -lftprintf && ./a.out
* E se eu tenho #include "deps/ft_printf/ft_printf.h" eu compilo:
* gcc deps/ft_printf/libftprintf.a src/main.c && ./a.out
* Em ambos casos eu compilei estando na raiz do projeto.
*/
#include "fractol.h"

/*
* return 1: if the complex number (the pixel coordinates) belongs 
* to the Mandelbrot set and do not escape to infinity
* return i: if the complex number escape to infinity and i is like
* how fast the number escapes.
*/
t_complex	convert_pixel_in_complex_number(int x, int y,
			int fractal_type, double zoom)
{
	t_complex	c;

	if (fractal_type == 1)
		c.x = (((float)x * 3.0 / WIDTH) - 2.0) / zoom;
	else
		c.x = (((float)x * 4.0 / WIDTH) - 2.0) / zoom;
	c.y = (((float)y * 2.0 / HEIGHT) - 1.0) / zoom;
	return (c);
}

/*
* It receives a pixel (x,y) e return the number of iterations that this pixel 
* (converted into Mandelbrot space) escape to the infinity.
* If return MAX_ITERATION that's because the pixel point didn't escape 
* to the infinity
*/
int	get_iteration_mandelbrot(int x, int y, double zoom)
{
	int			i;
	t_complex	c;
	double		x0;
	double		y0;
	double		xtemp;

	c = convert_pixel_in_complex_number(x, y, 1, zoom);
	i = 0;
	x0 = c.x;
	y0 = c.y;
	while ((c.x * c.x + c.y * c.y <= 2 * 2) && i < MAX_ITERATION)
	{
		xtemp = c.x * c.x - (c.y * c.y) + x0;
		c.y = 2 * c.x * c.y + y0;
		c.x = xtemp;
		i++;
	}
	return (i);
}

int	get_iteration_julia(int x, int y, double zoom, t_img image)
{
	int			i;
	t_complex	c;
	float		x0;
	float		y0;
	double		xtemp;

	c = convert_pixel_in_complex_number(x, y, 2, zoom);
	i = 0;
	x0 = image.re;
	y0 = image.im;
	while ((c.x * c.x + c.y * c.y <= 2 * 2) && i < MAX_ITERATION)
	{
		xtemp = c.x * c.x - (c.y * c.y) + x0;
		c.y = 2 * c.x * c.y + y0;
		c.x = xtemp;
		i++;
	}
	return (i);
}

void	plot_fractal(t_img *image)
{
	int		x;
	int		y;
	int		num_iteration;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (image->fractal_type == 2)
				num_iteration = get_iteration_julia(x, y,
						image->win->zoom, *image);
			else
				num_iteration = get_iteration_mandelbrot(x,
						y, image->win->zoom);
			my_mlx_pixel_put(image, x, y, define_color(num_iteration));
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window((*image).win->mlx_ptr,
		(*image).win->win_ptr, image->img_ptr, 0, 0);
}
