/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:01:40 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/18 17:19:52 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
    Con esta función determinamos los valores para que se produzca burningship.
    Su fórmula es z = z*z + c. Las variables z y c son números complejos,
	constan de un número real y otro imaginario.
    c_real y c_imaginario son el cálculo de la proporción del pixel en pantalla respecto al plano fractal.
    Esta fórmula se repite de manera recursiva, actualizando el valor de z.
    En cada iteración se comprueba si el resultado dado escapa los límites de mandelbrot (<= 4),
	para dibujar el pixel con un color diferente dependiendo del resultado.
*/
void	draw_burningship(t_fractol *fractal)
{
	burningship_algorithm(fractal);
	fractal_colors(fractal);
}

double	absolute_value(double z_real, double z_imaginary)
{
	double	absolute;

	absolute = 2 * (z_real * z_imaginary);
	if (absolute < 0)
		absolute *= -1;
	return (absolute);
}

void	burningship_algorithm(t_fractol *fractal)
{
	t_complex	z;
	double		z_temp_real;

	z.real = 0;
	z.imaginary = 0;
	z_temp_real = 0;
	fractal->iter = 0;
	while (fractal->iter < MAX_ITER)
	{
		z_temp_real = (z.real * z.real) - (z.imaginary * z.imaginary)
			+ fractal->c.real;
		z.imaginary = absolute_value(z.real, z.imaginary) - fractal->c.imaginary;
		z.real = z_temp_real;
		if ((z.real * z.real) + (z.imaginary * z.imaginary) >= 4)
			break ;
		fractal->iter++;
	}
}
