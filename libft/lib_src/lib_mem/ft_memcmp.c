/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:29:16 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:46:23 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*str1;
	unsigned char	*str2;

	a = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (a < n)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
			a++;
		}
		else
			return (*str1 - *str2);
	}
	return (0);
}
