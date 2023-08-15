/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:39:33 by cvallejo          #+#    #+#             */
/*   Updated: 2022/08/10 14:27:25 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Para imprimir un puntero, primero tenemos que escribir "0x" delante,
	y luego deberemos dividir entre 16 y trabajar con el resto */

int	ft_format_ptr(unsigned long long ptr)
{
	int	count;

	count = 2;
	write(1, "0x", 2);
	if (!ptr)
	{
		write(1, "0", 1);
		count++;
	}
	else
	{
		count += ft_hexabase(ptr, 0);
	}
	return (count);
}

int	ft_hexabase(unsigned long long num, int flag)
{
	static int	count;

	count = 0;
	if (num >= 16)
		ft_hexabase(num / 16, flag);
	if (flag == 0)
	{
		ft_putchar_pf("0123456789abcdef"[num % 16]);
		count++;
	}
	else
	{
		ft_putchar_pf("0123456789ABCDEF"[num % 16]);
		count++;
	}
	return (count);
}
