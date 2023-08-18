/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:49:19 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/18 16:12:00 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	graphic_proportion(t_fractol *fractal, int x, int y)
{
	fractal->c.real = fractal->min_real + (double)x * (fractal->max_real
			- fractal->min_real) / WIDTH;
	fractal->c.imaginary = fractal->max_imaginary - (double)y * (fractal->max_imaginary - fractal->min_imaginary) / HEIGHT;
}

void	pixel_in_window(t_fractol *fractal)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			graphic_proportion(fractal, x, y);
			fractal_selection(fractal);
			mlx_put_pixel(fractal->img, x, y, fractal->color);
			x++;
		}
		y++;
	}
}
