/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulga.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:35:39 by davifern          #+#    #+#             */
/*   Updated: 2023/09/18 17:28:05 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *) dst = color;
}

/*
* return 1: if the complex number (the pixel coordinates) belongs 
* to the Mandelbrot set and do not escape to infinity
* return i: if the complex number escape to infinity and i is like
* how fast the number escapes.
*/
//??????c.x, c.y????
t_complex	convert_pixel_in_complex_number(int x, int y)
{
	t_complex	c;

	c.x = (3 * (float)x) / 1920.0 + 2;
	c.y = (2 * (float)y) / 1080.0 + 1;
	return (c);
}

int	calculate_mandelbrot(x, y)
{
	int			i;
	t_complex	c;
	int			x0;
	int			y0;
	int			xtemp;
	
	c = convert_pixel_in_complex_number(x, y);
	i = 0;
	x0 = c.x;
	y0 = c.y;
	while (c.x * c.x + c.y * c.y <= 2 * 2 && i < 100) //pq 100? sei que com 100 ja da pra visualizar melhor o mandelbrot, mas quero entender melhor isso
	{
		xtemp = c.x * c.x - (c.y * c.y) + x0;
		c.y = 2 * c.x * c.y + y0;
		c.x = xtemp;
		i++;
	}
	if (i == 100)
		return (1);
	else
		return (0);
}

int	main(void)
{
	t_win	window;
	t_img	image;
	int		m;

	window.mlx_ptr = mlx_init();
	if (!window.mlx_ptr)
		return (1);
	window.win_ptr = mlx_new_window(window.mlx_ptr, 1920, 1080, "Fractal");
	if (!window.win_ptr)
		return (2);
	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, 1920, 1080);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), &(image.line_len), &(image.endian));

	int x = 0;
	int y = 0;
	while (y < 1080)
	{
		while (x < 1920)
		{
			m = calculate_mandelbrot(x, y);
			if (m == 1) //se hace 100 iteraciones
				put_pixel_img(image, x, y, 0x00000000); //pinto negro
			else //se salie antes porque el valor es major que 4
				put_pixel_img(image, x, y, 0xFFFFFFFF); //pinto blanco
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0,	0);
	mlx_loop(window.mlx_ptr);

	return (0);
}


