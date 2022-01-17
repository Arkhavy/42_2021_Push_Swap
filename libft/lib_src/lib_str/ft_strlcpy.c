/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:03:08 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:47:27 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	length;

	a = 0;
	length = ft_strlen(src);
	if (dstsize > 0)
	{
		while (a + 1 < dstsize && src[a])
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return (length);
}
