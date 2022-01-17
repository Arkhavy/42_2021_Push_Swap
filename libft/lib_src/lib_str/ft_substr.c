/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:50:20 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:47:57 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*newstr;
	size_t	s_len;

	if (!s)
		return (NULL);
	a = 0;
	s_len = ft_strlen(s);
	if (len > ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	newstr = malloc(sizeof(char) * len + 1);
	if (!newstr)
		return (NULL);
	while (s[start + a] && a < len && start < s_len)
	{
		newstr[a] = s[start + a];
		a++;
	}
	newstr[a] = '\0';
	return (newstr);
}
