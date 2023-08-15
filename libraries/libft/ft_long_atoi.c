/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:13:54 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/09 17:05:36 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkspaces(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

long int	ft_long_atoi(const char *str)
{
	int		i;
	long	aux;
	long	result;

	i = 0;
	aux = 1;
	i = ft_checkspaces((char *)str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			aux *= -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	result *= aux;
	if (aux > 0 && result < 0)
		return (-1);
	if (aux < 0 && result > 0)
		return (0);
	return (result);
}
