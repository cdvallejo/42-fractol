/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:05:47 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/29 17:50:35 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "libraries/MLX42/include/MLX42/MLX42.h"
# include "libraries/libft/libft.h"
# include <math.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1200
# define HEIGHT 1000
# define MAX_ITER 150

/*
    Struct for complex numbers:
    x -> real number
    y -> imaginary number
*/
typedef struct s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

/*
    Struct for fractal values:
*/
typedef struct s_fractol
{
	int			select;
	double		min_real;
	double		max_real;
	double		move_x;
	double		move_y;
	double		min_imaginary;
	double		max_imaginary;
	double		zoom;
	int			iter;
	int			color;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_complex	c;
	t_complex	julia_c;
}				t_fractol;

//fractol_bonus.c functions
void			mandelbrot_init(t_fractol *fractal);
void			julia_init(t_fractol *fractal, char **av);
void			init_fractol(t_fractol *fractal, char **av);
void			fractal_selection(t_fractol *fractal);
void			pixel_in_window(t_fractol *fractal);

//graphics_bonus.c functions
void			graphic_proportion(t_fractol *fractal, int x, int y);
void			pixel_in_window(t_fractol *fractal);

//colors_bonus.c functions
void			colors_mandelbrot(t_fractol *fractal);
void			colors_julia_2(t_fractol *fractal);
void			colors_julia_1(t_fractol *fractal);
void			fractal_colors(t_fractol *fractal);

//mandelbrot_bonus.c functions
void			draw_mandelbrot(t_fractol *fractal);
void			mandelbrot_algorithm(t_fractol *fractal);

//julia_bonus.c functions
void			draw_julia(t_fractol *fractal);
void			julia_algorithm(t_fractol *fractal);
void			fractal_colors(t_fractol *fractal);

//hooks_bonus.c functions
void			my_move_keys(mlx_key_data_t keydata, t_fractol *fractal);
void			my_keyhook(mlx_key_data_t keydata, void	*param);
void			scrollhook(double xdelta, double ydelta, void *param);

//utils_bonus.c functions
void			print_instructions(void);
int				check_sign(char *av);
double			ft_atof(char *av);
void			check_args(int ac, char **av, t_fractol *fractal);

//burningship_bonus.c functions
void			draw_burningship(t_fractol *fractal);
double			absolute_value(double z_real, double z_imaginary);
void			burningship_algorithm(t_fractol *fractal);

#endif