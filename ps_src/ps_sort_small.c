/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:01:41 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/11 11:11:15 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_inc/push_swap.h"

static void	ps_push_back(t_psw *psw)
{
	int	a;

	a = ps_find_first(psw);
	while (a < psw->sa.nb_elem)
	{
		if (psw->sb.stack[0] < psw->sa.stack[a] && psw->sb.stack[0] > 0)
		{
			while (a > 0)
				ps_rotate_index(psw, &a, 0, 'A');
			ps_push_a(psw);
			a = ps_find_first(psw);
		}
		else if (psw->sb.stack[0] > psw->sa.stack[a]
			&& psw->sa.stack[a + 1] == 0)
		{
			a = ps_check_a_from_start(psw);
			ps_push_a(psw);
			a = ps_find_first(psw);
		}
		a++;
	}
}

static void	ps_sort_three(t_psw *psw)
{
	if (psw->sa.stack[0] > psw->sa.stack[1]
		&& psw->sa.stack[0] < psw->sa.stack[2])
		ps_swap_a(psw);
	else if (psw->sa.stack[0] > psw->sa.stack[1]
		&& psw->sa.stack[1] < psw->sa.stack[2])
		ps_rotate_a(psw, 0, 1);
	else if (psw->sa.stack[0] < psw->sa.stack[1]
		&& psw->sa.stack[0] > psw->sa.stack[2])
		ps_revrotate_a(psw, 0, 1);
	else if (psw->sa.stack[0] > psw->sa.stack[1]
		&& psw->sa.stack[1] > psw->sa.stack[2])
	{
		ps_swap_a(psw);
		ps_revrotate_a(psw, 0, 1);
	}
	else if (psw->sa.stack[0] < psw->sa.stack[1]
		&& psw->sa.stack[1] > psw->sa.stack[2])
	{
		ps_swap_a(psw);
		ps_rotate_a(psw, 0, 1);
	}
}

void	ps_sort_small(t_psw *psw)
{
	if (psw->ac == 2)
	{
		if (psw->sa.stack[0] > psw->sa.stack[1])
			ps_swap_a(psw);
		return ;
	}
	while (psw->sa.nb_elem > 3)
		ps_push_b(psw);
	ps_sort_three(psw);
	while (psw->sb.nb_elem > 0)
		ps_push_back(psw);
	ps_rotate_to_first(psw, 'A');
}
