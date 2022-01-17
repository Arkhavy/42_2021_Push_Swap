/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:19:39 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:46:21 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*str;

	str = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		if (str[a] == (unsigned char)c)
			return ((void *)&s[a]);
		a++;
	}
	return (NULL);
}
