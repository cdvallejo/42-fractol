/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:30:11 by cvallejo          #+#    #+#             */
/*   Updated: 2022/04/26 11:50:44 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	size_dst;
	unsigned int	size_src;
	const char		*src2;

	i = 0;
	size_dst = 0;
	size_src = 0;
	src2 = src;
	while (dst[size_dst] != '\0')
		size_dst++;
	while (src2[size_src] != '\0')
		size_src++;
	if (dstsize == 0 || dstsize <= size_dst)
		return (size_src + dstsize);
	while (src[i] != '\0' && i < dstsize - size_dst - 1)
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_dst + size_src);
}
