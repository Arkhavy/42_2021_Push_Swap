/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:22:06 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:47:25 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;

	a = ft_strlen(dst);
	b = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize <= a)
		return (dstsize + ft_strlen(src));
	while (dstsize && (--dstsize - a) && src[b])
	{
		dst[a + b] = src[b];
		b++;
	}
	dst[a + b] = '\0';
	return (ft_strlen(src) + a);
}
