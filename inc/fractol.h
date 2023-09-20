/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:50:36 by davifern          #+#    #+#             */
/*   Updated: 2023/09/20 17:37:29 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../deps/libft/libft.h"
#include "ft_printf.h"

typedef struct s_win 
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

#define WIDTH 1920
#define HEIGHT 1080
#define MAX_ITERATION 500

#define BROWN_3 0x421E0F
#define DARK_VIOLET 0x19071A
#define DARKEST_BLUE 0x09012F
#define BLUE_5 0x040449
#define BLUE_4 0x000764
#define BLUE_3 0x0C2C8A
#define BLUE_2 0x1852B1
#define BLUE_1 0x397DD1
#define BLUE_0 0x86B5E5
#define LIGHTEST_BLUE 0xD3ECF8
#define LIGHTEST_YELLOW 0xF1E9BF
#define LIGHT_YELLOW 0xF8C95F
#define DIRTY_YELLOW 0xFFAA00
#define BROWN_0 0xCC8000
#define BROWN_1 0x995700
#define BROWN_2 0x6A3403