/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:06:39 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:46:12 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	a;

	a = n;
	if (a < 0)
	{
		ft_putchar_fd('-', fd);
		a = -a;
	}
	if (a > 9)
	{
		ft_putnbr_fd(a / 10, fd);
		a %= 10;
	}
	ft_putchar_fd(a + '0', fd);
}
