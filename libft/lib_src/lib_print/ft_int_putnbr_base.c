/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putnbr_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:31:02 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:45:59 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

int	ft_int_putnbr_base(unsigned int nbr, char *base)
{
	int				count;
	unsigned int	hexnb;
	size_t			baselen;

	count = 0;
	hexnb = nbr;
	baselen = ft_strlen(base);
	if (hexnb >= baselen)
		count += ft_int_putnbr_base(hexnb / baselen, base);
	count += ft_int_putchar(base[hexnb % baselen]);
	return (count);
}
