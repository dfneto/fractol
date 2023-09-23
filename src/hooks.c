/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:37:30 by davifern          #+#    #+#             */
/*   Updated: 2023/09/23 13:03:16 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* hook.c have functions related to the hooks
*/
#include "fractol.h"

int	scroll(int button, int x, int y, t_img *image)
{
	if (button == 5)
		image->win->zoom *= 1.5;
	if (button == 4)
		image->win->zoom /= 1.5;
	plot_fractal(image);
	(void) x;
	(void) y;
	return (0);
}

int	close_window(int keycode, t_win *window)
{
	if (keycode == ESC && window)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		exit(0);
	}
	return (0);
}

int	close_window_mouse(t_win *window)
{
	if (window)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		exit(0);
	}
	return (0);
}

void	set_hooks(t_win *window, t_img *image)
{
	mlx_hook(window->win_ptr, 17, 0, close_window_mouse, window);
	mlx_hook(window->win_ptr, 2, 0, close_window, window);
	mlx_hook(window->win_ptr, 4, 0, scroll, image);
	mlx_loop(window->mlx_ptr);
}
