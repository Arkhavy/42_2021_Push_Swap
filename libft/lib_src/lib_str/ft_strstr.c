/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:13:25 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:47:51 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	a;
	size_t	b;

	if (!needle || !needle[0])
		return ((char *)haystack);
	a = 0;
	while (haystack[a])
	{
		b = 0;
		if (haystack[a] == needle[b])
		{
			while (haystack[a + b] == needle[b])
			{
				b++;
				if (!needle[b])
					return ((char *)&haystack[a]);
			}
		}
		a++;
	}
	return (NULL);
}
