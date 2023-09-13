/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulga.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:35:39 by davifern          #+#    #+#             */
/*   Updated: 2023/09/13 20:00:18 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_win	tutorial;

	tutorial.mlx_ptr = mlx_init();
	if (!tutorial.mlx_ptr)
		return (1);
	tutorial.win_ptr = mlx_new_window(tutorial.mlx_ptr, 300, 300, "Hello World");
	if (!tutorial.win_ptr)
		return (2);
	mlx_loop(tutorial.mlx_ptr);
	return (0);
}