/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:46:03 by cvallejo          #+#    #+#             */
/*   Updated: 2022/08/10 14:27:55 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Si el número que llega es "-", imprimimos el signo y convertimos el número 
en positivo para que pase al siguiente 'if' que se emcargará de convertirlo a 
decimal. Finalmente, añadiendo un '0' lo convertimos en caracter*/

int	ft_format_dec(long num)
{
	int	count;

	count = ft_count_dec(num);
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num > 9)
	{
		ft_format_dec(num / 10);
		ft_format_dec(num % 10);
	}
	else
		ft_putchar_pf(num + '0');
	return (count);
}

/*Esta función sólo sirve para saber cuánto vale el contador que 
debemos retornar al final. Si es 0 el contador será uno y saldrá, 
pero si es menor a 0 contará uno por el signo '-' 
y continuará para dividirse por 10 hasta llegar a 0*/

int	ft_count_dec(long num)
{
	int	count;

	count = 0;
	if (num <= 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_format_undec(long num)
{
	int	count;

	count = ft_count_dec(num);
	if (num <= 4294967295 && num >= 0)
	{
		if (num > 9)
		{
			ft_format_dec(num / 10);
			ft_format_dec(num % 10);
		}
		else
			ft_putchar_pf(num + '0');
	}
	return (count);
}
