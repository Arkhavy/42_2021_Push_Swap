/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:04:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/11 11:32:47 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_inc/push_swap.h"

int	ps_count_size(int *stack)
{
	int	ac;

	ac = 0;
	while (stack[ac] > 0)
		ac++;
	return (ac);
}

void	ps_rotate_index(t_psw *psw, int *index_a, int *index_b, char c)
{
	if (c == 'A')
	{
		if (*index_a > psw->sa.nb_elem / 2)
			*index_a = ps_revrotate_a(psw, *index_a, 1);
		else
			*index_a = ps_rotate_a(psw, *index_a, 1);
	}
	else if (c == 'B')
	{
		if (*index_b > psw->sb.nb_elem / 2)
			*index_b = ps_revrotate_b(psw, *index_b, 1);
		else
			*index_b = ps_rotate_b(psw, *index_b, 1);
	}
	else
	{
		if (*index_a > psw->sa.nb_elem / 2 && *index_b > psw->sb.nb_elem / 2)
			ps_revrotate_r(psw, index_a, index_b);
		else
			ps_rotate_r(psw, index_a, index_b);
	}
}

void	ps_rotate_to_first(t_psw *psw, char c)
{
	int	a;
	int	ac;

	a = 0;
	if (c == 'A')
	{
		ac = psw->sa.nb_elem;
		while (psw->sa.stack[a] > 1)
			a++;
		while (a > 0)
			ps_rotate_index(psw, &a, 0, 'A');
	}
	else
	{
		ac = psw->sb.nb_elem;
		while (psw->sb.stack[a] > 1)
			a++;
		while (a > 0)
			ps_rotate_index(psw, 0, &a, 'B');
	}
}

int	ps_find_first(t_psw *psw)
{
	int	a;

	a = 0;
	while (psw->sa.stack[a] > 1)
		a++;
	if (psw->sa.stack[a] == 0)
	{
		ps_rotate_to_first(psw, 'B');
		ps_push_a(psw);
		return (0);
	}
	return (a);
}

int	ps_check_a_from_start(t_psw *psw)
{
	int	a;

	a = 0;
	while (psw->sb.stack[0] > psw->sa.stack[a] && psw->sa.stack[a] > 0)
		a++;
	if (psw->sa.stack[a] == 0)
		ps_rotate_to_first(psw, 'A');
	else
		while (a > 0)
			ps_rotate_index(psw, &a, 0, 'A');
	return (a);
}
