/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:01:40 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/22 14:09:46 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

/*
    Con esta función determinamos los valores para que se produzca burningship.
    Su fórmula es la misma de Mandelbrot, con la salvedad de que la operación
	para hallar la parte imaginaria de z ha de ser un valor absoluto.
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
		z.imaginary = absolute_value(z.real, z.imaginary)
			- fractal->c.imaginary;
		z.real = z_temp_real;
		if ((z.real * z.real) + (z.imaginary * z.imaginary) >= 4)
			break ;
		fractal->iter++;
	}
}