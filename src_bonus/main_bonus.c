/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:49:08 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/30 11:07:02 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

/*
	Programa que dibuja gráficamente un fractal: Mandelbrot, Julia o
	Burning Ship (sólo bonus). Orden del programa principal:
	1) Chequeo de argumentos.
	2) Inicialización del fractal elegido.
	3) Inicialización de la imagen en pantalla.
	4) Detección de acción de scroll.
	5) Detección de acciones de movimiento.
	6) Repetición de la llamada al lienzo gráfico.
	7) Finalización del proceso gráfico.
*/
int	main(int ac, char **av)
{
	t_fractol	fractal;

	check_args(ac, av, &fractal);
	init_fractol(&fractal, av);
	pixel_in_window(&fractal);
	mlx_image_to_window(fractal.mlx, fractal.img, 0, 0);
	mlx_scroll_hook(fractal.mlx, &scrollhook, &fractal);
	mlx_key_hook(fractal.mlx, &my_keyhook, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
