/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:01:40 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/15 18:46:15 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
    Con esta función determinamos los valores para que se produzca mandelbrot.
    Su fórmula es z = z*z + c. Las variables z y c son números complejos,
	constan de un número real y otro imaginario.
    c_real y c_imaginario son el cálculo de la proporción del pixel en pantalla respecto al plano fractal.
    Esta fórmula se repite de manera recursiva, actualizando el valor de z.
    En cada iteración se comprueba si el resultado dado escapa los límites de mandelbrot (<= 4),
	para dibujar el pixel con un color diferente dependiendo del resultado.
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
		z.imaginary = 2 * z.real * z.imaginary + fractal->julia_c.imaginary;
		z.real = z_temp_real;
		if ((z.real * z.real) + (z.imaginary * z.imaginary) >= 4)
			break ;
		fractal->iter++;
	}
}
