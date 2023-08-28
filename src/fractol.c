/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:01:40 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/25 17:52:41 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
    Inicialización de los valores del struct fractal.
	Los valores reales e imaginarios están sacados y adaptados de wikipedia
	para una visualización recomendada.
*/
void	mandelbrot_init(t_fractol *fractal)
{
	fractal->max_real = 1;
	fractal->min_real = -2;
	fractal->max_imaginary = 1.2;
	fractal->min_imaginary = -1.2;
	fractal->iter = 0;
	fractal->zoom = 1.0;
	fractal->move_x = 0;
	fractal->move_y = 0;
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
	if (!av[2])
	{
		fractal->julia_c.real = -0.21;
		fractal->julia_c.imaginary = 0.65;
	}
	else
	{
		fractal->julia_c.real = ft_atof(av[2]);
		fractal->julia_c.imaginary = ft_atof(av[3]);
	}
	fractal->max_real = 1;
	fractal->min_real = -2;
	fractal->max_imaginary = 1.2;
	fractal->min_imaginary = -1.2;
	fractal->zoom = 1.0;
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->iter = 0;
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "42 fract'ol: Julia | cvallejo",
			true);
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		exit(EXIT_FAILURE);
}

/*
	Función de paso para seleccionar el fractal
	que se va a inicializar.
*/
void	init_fractol(t_fractol *fractal, char **av)
{
	if (fractal->select == 1)
		mandelbrot_init(fractal);
	else if (fractal->select == 2)
		julia_init(fractal, av);
}

/*
	Función de paso para seleccionar el fractal
	que se va a dibujar.
*/
void	fractal_selection(t_fractol *fractal)
{
	if (fractal->select == 1)
		draw_mandelbrot(fractal);
	else if (fractal->select == 2)
		draw_julia(fractal);
}
