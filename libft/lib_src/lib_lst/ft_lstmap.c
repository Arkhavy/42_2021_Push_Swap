/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:27:15 by ljohnson          #+#    #+#             */
/*   Updated: 2021/12/03 12:46:44 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib_includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*firstlst;
	void	*content;

	firstlst = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		newlst = ft_lstnew(content);
		if (!newlst)
		{
			del(content);
			while (firstlst)
			{
				newlst = firstlst->next;
				del(firstlst->content);
				free(firstlst);
				firstlst = newlst;
			}
			return (NULL);
		}
		ft_lstadd_back(&firstlst, newlst);
		lst = lst->next;
	}
	return (firstlst);
}
