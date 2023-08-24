/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:20:40 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/22 14:10:02 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

/*
	Función que asigna a la tecla ESC cuando es presionada
	el cierre de ventana y la salida del programa.
*/
void	keyhook(void *param)
{
	mlx_t	*mlx_keys;

	mlx_keys = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{
		mlx_close_window(param);
		exit(EXIT_SUCCESS);
	}
}

/*
	Función que asigna el zoom.
*/
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
