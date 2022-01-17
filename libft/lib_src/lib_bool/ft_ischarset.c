/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_charset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 10:35:33 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/04 10:37:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

int	ft_ischarset(char c, char *set)
{
	size_t	a;

	a = 0;
	while (set[a])
	{
		if (c == set[a])
			return (1);
		a++;
	}
	return (0);
}
