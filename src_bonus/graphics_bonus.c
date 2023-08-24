/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:49:19 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/22 14:09:58 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

/*
	Función cuya operación matemática da como resultado
	el punto correspodinte del plano fractal (ejes real e imaginario)
	con respecto al plano visual (ejes x, y).
*/
void	graphic_proportion(t_fractol *fractal, int x, int y)
{
	fractal->c.real = fractal->min_real + (double)x * (fractal->max_real
			- fractal->min_real) / WIDTH;
	fractal->c.imaginary = fractal->max_imaginary - (double)y
		* (fractal->max_imaginary - fractal->min_imaginary) / HEIGHT;
}

/*
	Mediente este while se recorre la pantalla pixel a pixel para:
	1) Hallar los valores reales e imaginarios del valor c de la fórmula
	fractal respecto al plano visual (x, y).
	2) Iterar la fórmula del fractal corrrespondiente para saber qué ha de dibujar
	en ese pixel (dependiendo del número de iteraciones de la fórmula).
	3) Dibujar con la librería mlx ese pixel en el "lienzo".
*/
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
