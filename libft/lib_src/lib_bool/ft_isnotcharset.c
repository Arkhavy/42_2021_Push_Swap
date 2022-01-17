/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnotcharset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 08:48:34 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/10 08:49:13 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

int	ft_isnotcharset(char c, char *set)
{
	size_t	a;

	a = 0;
	while (set[a])
	{
		if (c != set[a])
			return (1);
		a++;
	}
	return (0);
}
