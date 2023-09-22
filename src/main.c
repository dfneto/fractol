/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:08:12 by davifern          #+#    #+#             */
/*   Updated: 2023/09/22 17:36:35 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
* 17 is the event DestroyNotify launched when we click the X 
* button to close a window
* 4 is the event ButtonPress launched when the mouse is clicked 
* and scroll is a botton pressed
* ----------------------------------------------------------------
* mlx_mouse_hook(window.win_ptr, scroll, &window) is equivalent to
* mlx_hook(window.win_ptr, 4, 0, scroll, &image);
*/
int	main(int argc, char *argv[])
{
	t_win	window;
	t_img	image;

	image.fractal_type = 1;
	if (argc >= 2)
	{
		image.re = ft_atof(argv[2]);
		image.im = ft_atof(argv[3]);
		image.fractal_type = 2;
	}
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
