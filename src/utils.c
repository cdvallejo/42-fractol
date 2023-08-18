/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:30:39 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/18 16:06:11 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>

void	print_instructions(void)
{
	ft_printf("\n********** Fractol 42 **********\n");
	ft_printf("\n• 'M' or 'm' for Mandelbrot\n");
	ft_printf("\n• 'J' or 'j' for Julia");
	ft_printf("\n For Julia, you have to add two decimal numbers as parameters");
	ft_printf("\n 	Examples: j 0.285 0.01 | j -0.70176 -0.3842 \n");
	ft_printf(" 		  j -0.7269 0.1889 | j -0.4 0.6 \n");
	ft_printf(" 		  j 0.45 0.1428 | j -0.835 0.2321 \n");
	ft_printf("\n- Use mouse wheel for zoom in/out. Press 'ESC' for exit\n\n");
	exit(1);
}

int	check_float(char *av)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i])
	{
		if (av[i] >= '0' && av[i] <= '9')
			i++;
		else if (av[i] == '.')
		{
			point++;
			if (point > 1)
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	check_sign(char *av)
{
	int	sign;

	sign = 0;
	if (av[0] == '-' || av[0] == '+')
	{
		if (av[0] == '-')
			sign = -1;
	}
	else
		sign = 1;
	return (sign);
}

double	ft_atof(char *av)
{
	double	sign;
	double	result;
	int		decimal;
	int		i;

	sign = check_sign(av);
	i = 0;
	result = 0;
	decimal = 0;
	while (av[i] != '\0')
	{
		if (av[i] == '.')
			decimal = 1;
		else if (ft_isdigit(av[i]) == 1)
		{
			if (decimal == 1)
				sign /= 10;
			result = result * 10.0 + av[i] - '0';
		}
		i++;
	}
	return (result * sign);
}

void	check_args(int ac, char **av, t_fractol *fractal)
{
	if (ac == 2 && (av[1][0] == 'm' || av[1][0] == 'M') && !av[1][1])
		fractal->select = 1;
	else if (ac == 4 && (av[1][0] == 'j' || av[1][0] == 'J') && !av[1][1])
	{
		if (check_float(av[2]) == 1 && check_float(av[3]) == 1)
			fractal->select = 2;
		else
			print_instructions();
	}
	else if (ac == 2 && (av[1][0] == 'b' || av[1][0] == 'B') && !av[1][1])
		fractal->select = 3;
	else
		print_instructions();
}
