/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:20:40 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/18 12:27:49 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	keyhook(void *param)
{
	mlx_t	*mlx_keys;

	mlx_keys = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{
		mlx_close_window(param);
		exit(EXIT_SUCCESS);
	}
	/*if (mlx_is_key_down(param, MLX_KEY_UP))
		fractal->img[0].y -= 10;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		fractal->img[0].y += 10;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		fractal->img[0].x -= 10;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		fractal->img[0].x += 10;*/
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	mlx_t	*mlx_keys;

	mlx_keys = param;
	xdelta = 0;
	// Simple up or down detection.
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
}
