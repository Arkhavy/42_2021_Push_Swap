/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:15:21 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/04 14:56:25 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

static int	count_str(const char *s, char c)
{
	size_t	a;
	size_t	nb_str;

	a = 0;
	nb_str = 0;
	while (s[a])
	{
		if ((a == 0) && s[0] != c)
			nb_str++;
		else if (s[a] != c && s[a - 1] == c)
			nb_str++;
		a++;
	}
	return (nb_str);
}

static char	*ft_splitdup(const char *s, char c)
{
	char	*str;
	size_t	a;

	a = 0;
	while (s[a] && s[a] != c)
		a++;
	str = malloc(sizeof(char) * (a + 1));
	if (!str)
		return (NULL);
	a = 0;
	while (s[a] && !(s[a] == c))
	{
		str[a] = s[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	nb_str;
	size_t	a;

	if (!s)
		return (NULL);
	a = 0;
	nb_str = count_str(s, c);
	str = malloc(sizeof(char *) * (nb_str + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s && *s != c)
		{
			str[a] = ft_splitdup(s, c);
			a++;
			while (*s && *s != c)
				s++;
		}
	}
	str[a] = NULL;
	return (str);
}
