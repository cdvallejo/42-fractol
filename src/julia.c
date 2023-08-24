/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:01:40 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/22 11:38:25 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
    Con esta función determinamos los valores para que se produzca Julia.
    Su fórmula es la misma de Mandelbrot, con la diferencia de que hay que
	indicarle los valores de c_real y c_imaginario. A su vez, z no empezará
	desde 0 cada vez como ocurría en Mandelbrot, sino que lo hará desde los
	valores indicados.
*/
void	draw_julia(t_fractol *fractal)
{
	julia_algorithm(fractal);
	fractal_colors(fractal);
}

void	julia_algorithm(t_fractol *fractal)
{
	t_complex	z;
	double		z_temp_real;

	z.real = fractal->c.real;
	z.imaginary = fractal->c.imaginary;
	z_temp_real = 0;
	fractal->iter = 0;
	while (fractal->iter < MAX_ITER)
	{
		z_temp_real = (z.real * z.real) - (z.imaginary * z.imaginary)
			+ fractal->julia_c.real;
		z.imaginary = 2 * (z.real * z.imaginary) + fractal->julia_c.imaginary;
		z.real = z_temp_real;
		if ((z.real * z.real) + (z.imaginary * z.imaginary) >= 4)
			break ;
		fractal->iter++;
	}
}
