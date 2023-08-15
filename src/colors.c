/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:32:44 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/15 18:46:08 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	colors_mandelbrot(t_fractol *fractal)
{
	if (fractal->iter == MAX_ITER)
		fractal->color = 0x000000FF;
	else if (fractal->iter <= 4)
		fractal->color = 0x002244FF;
	else if (fractal->iter > 4 && fractal->iter <= 8)
		fractal->color = 0x000080FF;
	else if (fractal->iter > 8 && fractal->iter <= 15)
		fractal->color = 0x0000FFFF;
	else if (fractal->iter > 15 && fractal->iter <= 25)
		fractal->color = 0xF9CEB7FF;
	else if (fractal->iter > 25 && fractal->iter <= 35)
		fractal->color = 0xD6C6BEFF;
	else if (fractal->iter > 35 && fractal->iter <= 45)
		fractal->color = 0xD6C6BEFF;
	else if (fractal->iter > 46 && fractal->iter <= 100)
		fractal->color = 0xE8EAA1FF;
	else if (fractal->iter > 100 && fractal->iter <= 120)
		fractal->color = 0xF9FE56FF;
	else if (fractal->iter > 120 && fractal->iter < 150)
		fractal->color = 0xFFFF00FF;
	else
		fractal->color = 0xFFFFFFFF;
}

void	colors_julia_2(t_fractol *fractal)
{
	if (fractal->iter > 76 && fractal->iter < 85)
		fractal->color = 0x345678FF;
	else if (fractal->iter > 86 && fractal->iter < 95)
		fractal->color = 0x456789FF;
	else if (fractal->iter > 96 && fractal->iter < 100)
		fractal->color = 0x56789AFF;
	else if (fractal->iter > 96 && fractal->iter < 105)
		fractal->color = 0x6789ABFF;
	else if (fractal->iter > 106 && fractal->iter < 115)
		fractal->color = 0x789ABCFF;
	else if (fractal->iter > 116 && fractal->iter < 125)
		fractal->color = 0x89ABCDFF;
	else if (fractal->iter > 126 && fractal->iter < 135)
		fractal->color = 0x9ABCDEFF;
	else if (fractal->iter > 136 && fractal->iter < 150)
		fractal->color = 0x000000FF;
	else
		fractal->color = 0x000000FF;
}

void	colors_julia_1(t_fractol *fractal)
{
	if (fractal->iter == MAX_ITER)
		fractal->color = 0x000000FF;
	else if (fractal->iter <= 4)
		fractal->color = 0x002244FF;
	else if (fractal->iter > 4 && fractal->iter <= 8)
		fractal->color = 0x000080FF;
	else if (fractal->iter > 8 && fractal->iter <= 10)
		fractal->color = 0x004488FF;
	else if (fractal->iter > 10 && fractal->iter <= 15)
		fractal->color = 0x000080FF;
	else if (fractal->iter > 15 && fractal->iter <= 25)
		fractal->color = 0x55CA22FF;
	else if (fractal->iter > 25 && fractal->iter <= 35)
		fractal->color = 0x24FF48FF;
	else if (fractal->iter > 35 && fractal->iter <= 45)
		fractal->color = 0x21EE42FF;
	else if (fractal->iter > 46 && fractal->iter <= 55)
		fractal->color = 0x1EDC3CFF;
	else if (fractal->iter > 56 && fractal->iter <= 65)
		fractal->color = 0x123456FF;
	else if (fractal->iter > 66 && fractal->iter < 75)
		fractal->color = 0x234567FF;
	else
		colors_julia_2(fractal);
}
void	fractal_colors(t_fractol *fractal)
{
	if (fractal->select == 1)
		colors_mandelbrot(fractal);
	else if (fractal->select == 2)
		colors_julia_1(fractal);
}
