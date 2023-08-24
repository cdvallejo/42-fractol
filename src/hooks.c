/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:20:40 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/22 17:43:02 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
	Función que asigna a la tecla ESC el cierre de ventana y del programa.
*/
void	my_keyhook(mlx_key_data_t keydata, void	*param)
{
	t_fractol	*fractal;

	fractal = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(fractal->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
		puts("ARRIBA");
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
		puts("ABAJO");
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	mlx_t	*mlx_keys;

	mlx_keys = param;
	xdelta = 0;
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
}
