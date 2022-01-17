/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 08:29:02 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:46:00 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

int	ft_int_putnbr(int n)
{
	long int	a;
	int			count;

	a = n;
	count = 0;
	if (a < 0)
	{
		count += ft_int_putchar('-');
		a = -a;
	}
	if (a > 9)
	{
		count += ft_int_putnbr(a / 10);
		a %= 10;
	}
	count += ft_int_putchar(a + '0');
	return (count);
}
