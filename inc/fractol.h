/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:50:36 by davifern          #+#    #+#             */
/*   Updated: 2023/09/23 13:01:30 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//do i need it???
#ifndef FRACTOL_H 
# define FRACTOL_H

# include <mlx.h>
# include "../deps/libft/libft.h"
# include "ft_printf.h"

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	double	zoom;
}		t_win;


/*
re and im are used just in case of julia set*/
typedef struct s_img
{
	t_win	*win;
	void	*img_ptr;
	char	*addr;
	float	im;
	float	re;
	int		bpp;
	int		endian;
	int		line_len;
	int		fractal_type;
}		t_img;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

int		define_color(int number_of_iterations);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		scroll(int button, int x, int y, t_img *image);
int		close_window(int keycode, t_win *window);
int		close_window_mouse(t_win *window);
void	plot_fractal(t_img *image);
float	ft_atof(const char *str);
void	set_hooks(t_win *window, t_img *image);
# define WIDTH 1080
# define HEIGHT 720
/* TODO: entender porque com 100 iterações já
* se visualiza bem o fractal
*/
# define MAX_ITERATION 100

# define ESC 53
# define LEFT_CLICK 1

# define BROWN_3 0x421E0F
# define DARK_VIOLET 0x19071A
# define DARKEST_BLUE 0x09012F
# define BLUE_5 0x040449
# define BLUE_4 0x000764
# define BLUE_3 0x0C2C8A
# define BLUE_2 0x1852B1
# define BLUE_1 0x397DD1
# define BLUE_0 0x86B5E5
# define LIGHTEST_BLUE 0xD3ECF8
# define LIGHTEST_YELLOW 0xF1E9BF
# define LIGHT_YELLOW 0xF8C95F
# define DIRTY_YELLOW 0xFFAA00
# define BROWN_0 0xCC8000
# define BROWN_1 0x995700
# define BROWN_2 0x6A3403

#endif