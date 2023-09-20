/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:50:36 by davifern          #+#    #+#             */
/*   Updated: 2023/09/20 17:04:34 by davifern         ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080

# define TURQUESA 	0X60FAD2
# define LILA_CLAR	0XCD74FC
# define LILA_MITJ	0XA236DC
# define LILA_FOSC	0X7103AC
# define ROSA		0XFC86C8
# define VERD		0X8FD19D
# define AZULCIELO	0X88CCF2
# define AZULMARIN	0X07093B
# define CORAL		0XFA535D
# define NARANJA	0XFE834D
# define BLANCOROTO	0XF2F2F2
# define NEGRE		0X000000