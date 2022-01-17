/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:52:25 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/14 16:19:11 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_inc/push_swap.h"

static void	ps_rotate_b_to_push(t_psw *psw)
{
	int	index;
	int	a;

	a = 0;
	index = 0;
	while (a < psw->sb.nb_elem)
	{
		if (psw->sb.stack[a] == psw->sb.nb_elem)
			index = a;
		a++;
	}
	while (index > 0)
		ps_rotate_index(psw, 0, &index, 'B');
}

static int	ps_check_indexes(t_psw psw, int tail, int head, int loop)
{
	int	a;

	if (loop == 1)
	{
		a = 0;
		while (a < psw.sa.nb_elem)
		{
			if (psw.sa.stack[a] <= head && psw.sa.stack[a] > tail)
				return (a);
			a++;
		}
	}
	else
	{
		a = psw.sa.nb_elem - 1;
		while (a > 0)
		{
			if (psw.sa.stack[a] <= head && psw.sa.stack[a] > tail)
				return (a);
			a--;
		}
	}
	return (-1);
}

static int	ps_check_current_pack(t_psw *psw, int tail, int head)
{
	int	index_start;
	int	index_end;
	int	a;

	a = 0;
	index_start = ps_check_indexes(*psw, tail, head, 1);
	index_end = ps_check_indexes(*psw, tail, head, 0);
	if (index_start == -1 && index_end == -1)
		return (0);
	if (index_end < index_start)
		while (index_end > 0)
			ps_rotate_index(psw, &index_end, 0, 'A');
	else
		while (index_start > 0)
			ps_rotate_index(psw, &index_start, 0, 'A');
	return (1);
}

static void	ps_2pack_sort(t_psw *psw, t_mark mk)
{
	int		a;

	a = 0;
	while (a < psw->nb_packs && psw->sa.nb_elem > 0)
	{
		while (ps_check_current_pack(psw, mk.tail_high, mk.head_high))
			ps_push_b(psw);
		while (ps_check_current_pack(psw, mk.tail_low, mk.head_low))
		{
			ps_push_b(psw);
			ps_rotate_b(psw, 0, 1);
		}
		mk.tail_low -= psw->size_pack;
		if (mk.tail_low <= 0)
			mk.tail_low = 0;
		mk.head_low -= psw->size_pack;
		mk.tail_high += psw->size_pack;
		mk.head_high += psw->size_pack;
		if (mk.head_high >= psw->ac)
			mk.head_high = psw->ac;
		a++;
	}
}

void	ps_sort_big(t_psw *psw)
{
	t_mark	mk;

	mk.tail_low = psw->sa.nb_elem / 2 - psw->size_pack;
	mk.head_low = psw->sa.nb_elem / 2;
	mk.tail_high = psw->sa.nb_elem / 2;
	mk.head_high = psw->sa.nb_elem / 2 + psw->size_pack;
	ps_2pack_sort(psw, mk);
	while (psw->sa.nb_elem > 0)
		ps_push_b(psw);
	while (psw->sb.nb_elem > 0)
	{
		ps_rotate_b_to_push(psw);
		ps_push_a(psw);
	}
	ps_rotate_to_first(psw, 'A');
}
