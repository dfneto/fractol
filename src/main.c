/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:08:12 by davifern          #+#    #+#             */
/*   Updated: 2023/09/23 14:35:19 by davifern         ###   ########.fr       */
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

int	check_numbers(char *argv[])
{
	int	i;
	int	idx;
	int	check;

	idx = 2;
	while (argv[idx] != NULL)
	{
		i = -1;
		check = 0;
		if (argv[idx][0] == '-' || argv[idx][0] == '+')
			i++;
		while (argv[idx][++i])
		{
			if (argv[idx][i] == '.')
				check++;
			if ((argv[idx][i] != '.' && !ft_isdigit(argv[idx][i]))
				|| check == 2)
				return (1);
		}
		idx++;
	}
	return (0);
}

int	has_args_error(t_img *image, int argc, char *argv[])
{
	if (argc == 1 || argc > 4 || (ft_strncmp(argv[1], "1", 2) == 0
			&& argv[2] != NULL) || (ft_strncmp(argv[1], "2", 2) == 0
			&& argv[2] != NULL && argv[3] == NULL) || (argv[2] != NULL
			&& argv[3] != NULL && check_numbers(argv)))
	{
		ft_printf("\t1 - to Mandelbrot\n\t2 - to Julia -> "
			"Ex: ./fractol 2 param1 param2 (both optional)\n");
		return (1);
	}
	if (ft_strncmp(argv[1], "1", 2) == 0)
		image->fractal_type = 1;
	else if (ft_strncmp(argv[1], "2", 2) == 0 && argv[2] == NULL)
	{
		image->re = 0.285;
		image->im = -0.01;
		image->fractal_type = 2;
	}
	else
	{
		image->re = ft_atof(argv[2]);
		image->im = ft_atof(argv[3]);
		image->fractal_type = 2;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_win	window;
	t_img	image;

	if (has_args_error(&image, argc, argv))
		return (0);
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
	set_hooks(&window, &image);
	return (0);
}
