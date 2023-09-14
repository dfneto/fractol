/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:50:30 by davifern          #+#    #+#             */
/*   Updated: 2023/09/14 16:03:14 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	(void) vars;
	ft_printf("Hello from key_hook!\n");
	ft_printf("The keycode: %d\n", keycode);
	return (0);
}

int	close_window(int keycode, t_vars *vars)
{
	(void) vars;
	ft_printf("Hello from MOUSE!\n");
	ft_printf("The keycode: %d\n", keycode);
	return (0);
}

// int	main(void)
// {
//     // t_data	img;

// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");

// 	// img.img = mlx_new_image(mlx, 1920, 1080);
//     // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 	// 							&img.endian);
    
// 	// int	i = 0;
// 	// while (i < 1000)
// 	// {
// 	// 	my_mlx_pixel_put(&img, i, 1080/2, 0x00FF0000);
// 	// 	i++;
// 	// }
// 	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_mouse_hook(vars.win, close_window, &vars);
// 	mlx_loop(vars.mlx);
// }