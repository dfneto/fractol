/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:31:19 by davifern          #+#    #+#             */
/*   Updated: 2023/09/21 19:46:03 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
* return 1: if the complex number (the pixel coordinates) belongs 
* to the Mandelbrot set and do not escape to infinity
* return i: if the complex number escape to infinity and i is like
* how fast the number escapes.
*/
t_complex	convert_pixel_in_complex_number(int x, int y, double zoom)
{
	t_complex	c;

	c.x = (((float)x * 3.0 / WIDTH) - 2.0) / zoom;
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

	c = convert_pixel_in_complex_number(x, y, zoom);
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

void	plot_fractal(t_img *image)
{
	int		x;
	int		y;
	int		number_of_iterations;
	int		color;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			number_of_iterations = get_iteration_mandelbrot(x,
					y, image->win->zoom);
			color = define_color(number_of_iterations);
			my_mlx_pixel_put(image, x, y, color);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window((*image).win->mlx_ptr,
		(*image).win->win_ptr, image->img_ptr, 0, 0);
}

/*
* 17 is the event DestroyNotify launched when we click the X 
* button to close a window
* 4 is the event ButtonPress launched when the mouse is clicked 
* and scroll is a botton pressed
* ----------------------------------------------------------------
* mlx_mouse_hook(window.win_ptr, scroll, &window) is equivalent to
* mlx_hook(window.win_ptr, 4, 0, scroll, &image);
*/
int	main(void)
{
	t_win	window;
	t_img	image;

	window.mlx_ptr = mlx_init();
	if (!window.mlx_ptr)
		return (1);
	window.win_ptr = mlx_new_window(window.mlx_ptr, WIDTH, HEIGHT, "Fractol");
	if (!window.win_ptr)
		return (2);
	image.img_ptr = mlx_new_image(window.mlx_ptr, WIDTH, HEIGHT);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp, 
			&image.line_len, &image.endian);
	window.zoom = 1;
	image.win = &window;
	plot_fractal(&image);
	mlx_hook(window.win_ptr, 17, 0, close_window_mouse, &window);
	mlx_hook(window.win_ptr, 2, 0, close_window, &window);
	mlx_hook(window.win_ptr, 4, 0, scroll, &image);
	mlx_loop(window.mlx_ptr);
	return (0);
}