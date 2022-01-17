/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:01:23 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:47:47 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0 || len < ft_strlen(needle) - 1)
		return (NULL);
	a = 0;
	while (haystack[a] && a < len - ft_strlen(needle) + 1)
	{
		b = 0;
		while (haystack[a + b] == needle[b] && b <= len)
		{
			b++;
			if (!(needle[b] != '\0' && b != len))
				return ((char *)&haystack[a]);
		}
		a++;
	}
	return (NULL);
}
