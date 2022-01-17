/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:27:03 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:46:35 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

void	ft_lstadd_front(t_list **alst, t_list *newlst)
{
	if (alst)
	{
		newlst->next = *alst;
		*alst = newlst;
	}
}
