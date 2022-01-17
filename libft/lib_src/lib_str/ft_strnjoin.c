/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:12:39 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:47:45 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, ssize_t index)
{
	char	*str;
	int		a;
	int		b;

	if (!s1 && !s2)
		return (NULL);
	a = 0;
	b = 0;
	str = malloc (sizeof(char) * (ft_strlen(s1) + index + 1));
	if (!str)
		return (NULL);
	while (s1[a])
	{
		str[a] = s1[a];
		a++;
	}
	while (b < index)
	{
		str[a + b] = s2[b];
		b++;
	}
	str[a + b] = '\0';
	return (str);
}
