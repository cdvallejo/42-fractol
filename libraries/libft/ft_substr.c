/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:52:15 by cvallejo          #+#    #+#             */
/*   Updated: 2023/03/24 16:52:49 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			j;
	char			*substr;
	unsigned int	len_s;

	len_s = ft_strlen(s);
	if (start >= len_s || len_s == 0)
		return (ft_strdup(""));
	if (len > len_s)
		len = len_s;
	if (len > (len_s - (int)start))
		len = (len_s - (int)start);
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && i < start + len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	return (substr[j] = '\0', substr);
}
