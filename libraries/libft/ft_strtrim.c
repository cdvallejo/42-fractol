/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:47:03 by cvallejo          #+#    #+#             */
/*   Updated: 2022/04/28 15:29:04 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*newstr;

	if (!s1 || !set)
		return (0);
	while (ft_strchr(set, *s1) && *s1 != 0)
		s1++;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len]) && len != 0)
		len--;
	newstr = ft_substr(s1, 0, len + 1);
	return (newstr);
}
