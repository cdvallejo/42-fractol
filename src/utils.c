/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:30:39 by cvallejo          #+#    #+#             */
/*   Updated: 2023/08/28 10:44:59 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
	Imprime por pantalla las instrucción del programa en caso de que se
	introduzca un parámetro erróneo o ninguno en su ejecución.
*/
void	print_instructions(void)
{
	ft_printf("\n********** Fract'ol 42 **********\n");
	ft_printf("\n• Write 'M' or 'm' for Mandelbrot.\n");
	ft_printf("\n• Write 'J' or 'j' for Julia.");
	ft_printf("\n For Julia, add two decimal numbers as parameters.");
	ft_printf("\n Examples:");
	ft_printf("\n 	 	  j 0.285 0.01 | j -0.70176 -0.3842 \n");
	ft_printf(" 		  j -0.7269 0.1889 | j -0.4 0.6 \n");
	ft_printf(" 		  j 0.45 0.1428 | j -0.835 0.2321 \n");
	ft_printf("\n		  (Default value: j -0.21 0.65)\n");
	ft_printf("\n- Close or press 'ESC' on fract'ol window for exit.\n\n");
	exit(1);
}

/*
	(Sólo para Julia): Comprueba si los números introducidos son double.
	Si no, volverá a imprimir las instrucciones.
*/
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

/*
	(Sólo para Julia): Subfunción para ft_atof para comprobar el signo
	positivo o negativo de un número introducido.
*/
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

/*
	(Sólo para Julia): Convierte los argumentos en double.
*/
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

/*
	Parseo de los parámetros introducidos y categoriza el fractal
	introducido.
*/
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
	else if (ac == 2 && (av[1][0] == 'j' || av[1][0] == 'J') && !av[1][1])
		fractal->select = 2;
	else
		print_instructions();
}
