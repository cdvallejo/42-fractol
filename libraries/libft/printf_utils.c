/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:47:34 by cvallejo          #+#    #+#             */
/*   Updated: 2022/08/10 13:42:16 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_pf(char *ptr)
{
	int	count;

	count = 0;
	while (!ptr)
	{
		count++;
	}
	return (count);
}

void	ft_putchar_pf(int c)
{
	write(1, &c, 1);
}

void	ft_putstr_pf(char *s)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}
