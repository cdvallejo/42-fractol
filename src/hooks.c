/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:20:40 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/28 10:33:50 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
	Función que asigna el botonado de flechas de movimiento.
*/
void	my_move_keys(mlx_key_data_t keydata, t_fractol *fractal)
{
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
	{
		fractal->move_y += 0.1 * fractal->zoom;
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
	{
		fractal->move_y -= 0.1 * fractal->zoom;
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
	{
		fractal->move_x -= 0.1 * fractal->zoom;
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
	{
		fractal->move_x += 0.1 * fractal->zoom;
	}
}

/*
	Función principal que llama a la función my_keyhook (tiene asignado el
	botonado y sus acciones).
	Si el usuario pulsa ESC se cierra la ventana y el programa termina.
*/
void	my_keyhook(mlx_key_data_t keydata, void	*param)
{
	t_fractol	*fractal;

	fractal = param;
	my_move_keys(keydata, fractal);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(fractal->mlx);
		exit(EXIT_SUCCESS);
	}
	pixel_in_window(fractal);
}

/*
	Función de la propia librería gráfica para asignar a la rueda del ratón.
	Sólo se usa ydelta (movimiento ascendente y descendente de la rueda).
*/
void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractal;

	fractal = param;
	xdelta = 0;
	if (ydelta > 0)
	{
		fractal->zoom /= 1.2;
	}
	else if (ydelta < 0)
	{
		fractal->zoom *= 1.2;
	}
	pixel_in_window(fractal);
}
