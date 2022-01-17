/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:54:23 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:47:12 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

static size_t	count_char(long nb)
{
	size_t	a;

	a = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		a++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		a++;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	a;

	nb = n;
	a = count_char(nb);
	str = malloc(sizeof(char) * a + 1);
	if (!str)
		return (NULL);
	str[a] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[a - 1] = '0' + (nb % 10);
		nb = nb / 10;
		a--;
	}
	return (str);
}
