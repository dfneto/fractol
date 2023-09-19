/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:50:36 by davifern          #+#    #+#             */
/*   Updated: 2023/09/19 21:16:24 by davifern         ###   ########.fr       */
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