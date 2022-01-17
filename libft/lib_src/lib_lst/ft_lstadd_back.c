/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:27:01 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:46:32 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *newlst)
{
	t_list	*last;

	last = NULL;
	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = newlst;
		}
		else
			*alst = newlst;
	}
}
