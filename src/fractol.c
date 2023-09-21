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

    // c.x = (((float)x * 3.0 / 1920.0) - 2.0);
	// c.y = 1.0 - ((float)y * 2.0 / 1080.0);
	c.x = (((float)x * 3.0 / 1920.0) - 2.0) / zoom;
	c.y = (((float)y * 2.0 / 1080.0) - 1.0) / zoom;
	return (c);
}

/*
* It receives a pixel (x,y) e return the iteration that this pixel (converted into Mandelbrot space) escape to the infinity.
* If return MAX_ITERATION that's because the pixel point didn't escape to the infinity
*/
int	get_num_of_iteration_when_pixel_escape_in_mandelbrot_set(int x, int y, int zoom)
{
	int			i;
	t_complex	c;
	double			x0;
	double			y0;
	double			xtemp;
	
	c = convert_pixel_in_complex_number(x, y, zoom);
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
	if (keycode == ESC && window)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		exit(1); //can i use it? and why 1?
	}
	return (0);
}

// int	close_window_mouse(int button, int mouse_x, int mouse_y, t_win *window)
int	close_window_mouse(t_win *window)
{
	if (window)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		// printf("mouse x: %d, mouse y: %d\n", mouse_x, mouse_y);
		exit(1); //can i use it? and why 1?
	}
	return (0);
}

void	plot_fractal(t_img *image, int zoom)
{
	int     x;
    int     y;
    int     number_of_iterations;
	int		color;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
            number_of_iterations = get_num_of_iteration_when_pixel_escape_in_mandelbrot_set(x, y, zoom);
			color = define_color(number_of_iterations);
			my_mlx_pixel_put(image, x, y, color); 
			x++;
		}
		y++;
		x = 0;
	}
	// mlx_put_image_to_window((*image).win.mlx_ptr, (*image).win.win_ptr, (*image).img_ptr, 0, 0);
	// mlx_put_image_to_window(image->win.mlx_ptr, image->win.win_ptr, image->img_ptr, 0, 0);
}

int	scroll(int button, int x, int y, void *image)
{
	int	zoom;

	zoom = 0;
	if (button == 5)
		plot_fractal(image, 2);
	if (button == 4)
		plot_fractal(image, 2);
	(void) x;
	(void) y;
	return (0);
}

int	main(void)
{
    t_win	window;
	t_img	image;
    
	window.mlx_ptr = mlx_init();
    if (!window.mlx_ptr)
		return (1);
	window.win_ptr = mlx_new_window(window.mlx_ptr, 1920, 1080, "Fractol");
    if (!window.win_ptr)
		return (2);
	image.img_ptr = mlx_new_image(window.mlx_ptr, 1920, 1080);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp, &image.line_len,
								&image.endian);
	// image.win = &window;

	plot_fractal(&image, 1);
	
	/*sinal 17 eh um sinal que o sistema enviia quando destrói, no caso quando fechamos a janela*/
	mlx_hook(window.win_ptr, 17, 0, close_window_mouse, &window);
	mlx_hook(window.win_ptr, 2, 0, close_window, &window);
	mlx_hook(window.win_ptr, 4, 0, scroll, &image); // mlx_mouse_hook(window.win_ptr, scroll, &window); sao equivalentes //4 eh o evento ButtonPress e o scroll é um botão pressionado
	
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img_ptr, 0, 0);
	mlx_loop(window.mlx_ptr);
    return (0);
}