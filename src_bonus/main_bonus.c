/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:49:08 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/28 11:22:50 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

//system("leaks -q fractol");

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

/*
mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		g_img->instances[0].y -= 10;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		g_img->instances[0].y += 10;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		g_img->instances[0].x -= 10;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		g_img->instances[0].x += 10;
}

int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "Cvallejo", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 64, 64);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
*/