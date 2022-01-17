/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:58:24 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/11 16:09:39 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_inc/push_swap.h"

static int	ps_check_sort(t_psw psw)
{
	int	a;

	a = 0;
	while (a < psw.ac)
	{
		if (psw.sb.stack[a] > 0 || psw.sa.stack[a] != a + 1)
			return (0);
		a++;
	}
	return (1);
}

void	push_swap(t_psw psw)
{
	psw.sa.nb_elem = ps_count_size(psw.sa.stack);
	psw.sb.nb_elem = ps_count_size(psw.sb.stack);
	while (!ps_check_sort(psw))
	{
		if (psw.ac <= 6)
			ps_sort_small(&psw);
		else
		{
			psw.nb_packs = ps_get_nb_packs(psw.ac);
			psw.size_pack = ps_get_sizeof_packs(psw.ac);
			ps_sort_big(&psw);
		}
	}
}
