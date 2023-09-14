/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulga.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:35:39 by davifern          #+#    #+#             */
/*   Updated: 2023/09/14 23:42:47 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *) dst = color;
}

int	main(void)
{
	t_win	tutorial;
	t_img	image_4x4;

	tutorial.mlx_ptr = mlx_init();
	if (!tutorial.mlx_ptr)
		return (1);
	tutorial.win_ptr = mlx_new_window(tutorial.mlx_ptr, 300, 300, "Hello World");
	if (!tutorial.win_ptr)
		return (2);


	image_4x4.win = tutorial;
	image_4x4.img_ptr = mlx_new_image(tutorial.mlx_ptr, 300, 300);
	image_4x4.addr = mlx_get_data_addr(image_4x4.img_ptr, &(image_4x4.bpp), &(image_4x4.line_len), &(image_4x4.endian));

	int x = 0;
	int y = 0;
	while(x < 300)
	{
		while (y < 300)
		{
			put_pixel_img(image_4x4, x, y, 0x00FF0000);
			m = calculate_mandelbrot(x, y);
			if (m == 1) //se hace 100 iteraciones
				pinto negro
			else //se salie antes porque el valor es major que 4
				pinto blanco
			y++;
		}
		x++;
		y = 0;
	}
	mlx_put_image_to_window(image_4x4.win.mlx_ptr, image_4x4.win.win_ptr, image_4x4.img_ptr, 0,	0);
	mlx_loop(tutorial.mlx_ptr);

	return (0);
}


calculate_mandelbrot(x, y)
{
	int i = 0;
	while (z < 4 && i < 100)
	{
		z = ...
		i++;
	}

}