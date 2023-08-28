/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:49:19 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/25 17:57:37 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
	Función cuya operación matemática da como resultado
	el punto correspodinte del plano fractal (ejes real e imaginario)
	con respecto al plano visual (ejes x, y).
	La segunda operación entre paréntesis recalcula el plano visual
	en cada eje si el usuario ha hecho zoom o ha pulsado las teclas de dirección.
*/
void	graphic_proportion(t_fractol *fractal, int x, int y)
{
	if (fractal->select == 2)
	{
		fractal->c.real = (fractal->min_real + (double)x * (fractal->max_real
					- fractal->min_real) * fractal->zoom / WIDTH + 0.5)
			+ ((fractal->max_real - fractal->min_real) * (1 - fractal->zoom) / 2
				+ fractal->move_x);
	}
	else
		fractal->c.real = (fractal->min_real + (double)x * (fractal->max_real
					- fractal->min_real) * fractal->zoom / WIDTH)
			+ ((fractal->max_real - fractal->min_real) * (1 - fractal->zoom) / 2
				+ fractal->move_x);
	fractal->c.imaginary = (fractal->max_imaginary - (double)y
			* ((fractal->max_imaginary - fractal->min_imaginary) * fractal->zoom
			/ HEIGHT) - (fractal->max_imaginary - fractal->min_imaginary) * (1
				- fractal->zoom) / 2 + fractal->move_y);
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
