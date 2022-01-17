/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:13:18 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:47:09 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

int	ft_int_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	if (!s)
		return (-1);
	while (s[a])
	{
		if (s[a] == (char)c)
			return (a);
		a++;
	}
	if (s[a] == (char)c)
		return (a);
	return (-1);
}
