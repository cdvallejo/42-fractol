/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:27:59 by cvallejo          #+#    #+#             */
/*   Updated: 2022/08/10 14:36:54 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennum(long long nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
		count++;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long long	num;

	num = (long long)n;
	str = (char *)malloc(sizeof(char) * (ft_lennum(num) + 1));
	if (str == 0)
		return (NULL);
	count = ft_lennum(num);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[count] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[--count] = (num % 10) + 48;
		num = num / 10;
	}
	return (str);
}
