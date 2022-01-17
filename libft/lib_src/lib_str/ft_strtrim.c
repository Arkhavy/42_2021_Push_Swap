/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 08:38:06 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:47:54 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

static int	ft_trimcmp(const char s1, const char *set)
{
	size_t	d;

	d = 0;
	while (set[d])
	{
		if (set[d] == s1)
			return (1);
		d++;
	}
	return (0);
}

static int	ft_start(const char *s1, const char *set)
{
	size_t	a;

	a = 0;
	while (ft_trimcmp(s1[a], set) == 1)
		a++;
	return (a);
}

static int	ft_end(const char *s1, const char *set)
{
	size_t	c;

	c = ft_strlen(s1);
	while (c > 0 && ft_trimcmp(s1[c - 1], set) == 1)
		c--;
	return (c);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	a;
	size_t	b;
	size_t	c;

	if (!s1)
		return (NULL);
	a = ft_start(s1, set);
	b = 0;
	c = ft_end(s1, set);
	if (a > c)
		return (ft_strdup(""));
	else
	{
		str = malloc(sizeof(char) * (c - a + 1));
		if (!str)
			return (NULL);
		while (a < c)
			str[b++] = s1[a++];
		str[b] = '\0';
	}
	return (str);
}
