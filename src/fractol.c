#include "fractol.h"

/*
* return 1: if the complex number (the pixel coordinates) belongs 
* to the Mandelbrot set and do not escape to infinity
* return i: if the complex number escape to infinity and i is like
* how fast the number escapes.
*/
t_complex	convert_pixel_in_complex_number(int x, int y)
{
	t_complex	c;

    c.x = (((float)x * 3.0 / 1920.0) - 2.0);
	c.y = 1.0 - ((float)y * 2.0 / 1080.0);
	return (c);
}

/*
* It receives a pixel (x,y) e return the iteration that this pixel (converted into Mandelbrot space) escape to the infinity.
* If return MAX_ITERATION that's because the pixel point didn't escape to the infinity
*/
int	get_num_of_iteration_when_pixel_escape_in_mandelbrot_set(int x, int y)
{
	int			i;
	t_complex	c;
	double			x0;
	double			y0;
	double			xtemp;
	
	c = convert_pixel_in_complex_number(x, y);
	i = 0;
	x0 = c.x;
	y0 = c.y;
	while ((c.x * c.x + c.y * c.y <= 2 * 2) && i < MAX_ITERATION) //pq 100? sei que com 100 ja da pra visualizar melhor o mandelbrot, mas quero entender melhor isso
	{
		xtemp = c.x * c.x - (c.y * c.y) + x0;
		c.y = 2 * c.x * c.y + y0;
		c.x = xtemp;
		i++;
	}
	return (i);
}

int	close_window(int keycode, t_win *window)
{
	if ((keycode == ESC || keycode == LEFT_CLICK) && window)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		exit(1); //can i use it? and why 1?
	}
	return (0);
}

int	main(void)
{
    t_win	window;
	t_img	image;
    int     x;
    int     y;
    int     number_of_iterations;
	int		color;

	window.mlx_ptr = mlx_init();
    if (!window.mlx_ptr)
		return (1);
	window.win_ptr = mlx_new_window(window.mlx_ptr, 1920, 1080, "Fractol");
    if (!window.win_ptr)
		return (2);
	image.img_ptr = mlx_new_image(window.mlx_ptr, 1920, 1080);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp, &image.line_len,
								&image.endian);
	x = 0;
	y = 0;
	while (y < 1080)
	{
		while (x < 1920)
		{
            number_of_iterations = get_num_of_iteration_when_pixel_escape_in_mandelbrot_set(x, y);
			color = define_color(number_of_iterations);
			my_mlx_pixel_put(&image, x, y, color); 
			x++;
		}
		y++;
		x = 0;
	}
	
	// mlx_hook(window.win_ptr, 2, 1L<<0, mlx_destroy_window, &window);
	mlx_hook(window.win_ptr, 2, 0, close_window, &window);
	// mlx_hook(window.win_ptr, 4, 0, close_window, &window);
	mlx_hook(window.win_ptr, 17, 0, close_window, &window);
	//mlx_key_hook(window.win_ptr, close_window, &window);
	//mlx_mouse_hook(window.win_ptr, close_window, &window);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img_ptr, 0, 0);
	mlx_loop(window.mlx_ptr);
    return (0);
}