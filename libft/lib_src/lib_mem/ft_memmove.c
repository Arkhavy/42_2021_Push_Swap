/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:18:11 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:46:27 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		a;

	if (!dst && !src)
		return (NULL);
	a = 0;
	if (dst <= src)
	{
		while (a < n)
		{
			((char *)dst)[a] = ((char *)src)[a];
			a++;
		}
	}
	else if (dst > src)
	{
		while (n > 0)
		{
			((char *)dst)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	return (dst);
}
