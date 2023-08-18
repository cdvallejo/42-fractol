/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:01:40 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/18 17:17:27 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>
/*
    Inicialización de los valores del struct fractal. Los valores reales e imaginarios están
    sacados del complejo de Mandelbrot para una visualización recomendada:
    https://es.wikipedia.org/wiki/Conjunto_de_Mandelbrot#/media/Archivo:Mandelset_hires.png
    Los loops máximos son para evitar los resultados de 0 y 1 al infinito en el procesamiento prosterior del algoritmo.
*/
void	mandelbrot_init(t_fractol *fractal)
{
	fractal->max_real = 1;
	fractal->min_real = -2;
	fractal->max_imaginary = 1.2;
	fractal->min_imaginary = -1.2;
	fractal->iter = 0;
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "42 fract'ol: Mandelbrot | cvallejo",
			true);
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		exit(EXIT_FAILURE);
}

void	julia_init(t_fractol *fractal, char **av)
{
	fractal->julia_c.real = ft_atof(av[2]);
	fractal->julia_c.imaginary = ft_atof(av[3]);
	fractal->max_real = 1.6;
	fractal->min_real = -1.6;
	fractal->max_imaginary = 1.6;
	fractal->min_imaginary = -1.6;
	fractal->iter = 0;
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "42 fract'ol: Julia | cvallejo",
			true);
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		exit(EXIT_FAILURE);
}

void	burningship_init(t_fractol *fractal)
{
	fractal->max_real = 1.2;
	fractal->min_real = -2;
	fractal->max_imaginary = 1.8;
	fractal->min_imaginary = -0.7;
	fractal->iter = 0;
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "42 fract'ol: Burning Ship | cvallejo",
			true);
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		exit(EXIT_FAILURE);
}

void	init_fractol(t_fractol *fractal, char **av)
{
	if (fractal->select == 1)
		mandelbrot_init(fractal);
	else if (fractal->select == 2)
		julia_init(fractal, av);
	else if (fractal->select == 3)
		burningship_init(fractal);
}

void	fractal_selection(t_fractol *fractal)
{
	if (fractal->select == 1)
		draw_mandelbrot(fractal);
	else if (fractal->select == 2)
		draw_julia(fractal);
	else if (fractal->select == 3)
		draw_burningship(fractal);
}
