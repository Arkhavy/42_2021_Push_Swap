/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_revrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:52:48 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/11 15:25:09 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_inc/push_swap.h"

int	ps_revrotate_a(t_psw *psw, int index, int bol)
{
	int	a;
	int	ret;
	int	ac;

	ac = psw->sa.nb_elem;
	a = ac - 1;
	ret = psw->sa.stack[a];
	if (index == a)
		index = 0;
	else
		index++;
	while (a > 0)
	{
		psw->sa.stack[a] = psw->sa.stack[a - 1];
		a--;
	}
	psw->sa.stack[0] = ret;
	if (bol == 1)
		ft_putendl_fd("rra", 1);
	return (index);
}

int	ps_revrotate_b(t_psw *psw, int index, int bol)
{
	int	a;
	int	ret;
	int	ac;

	ac = psw->sb.nb_elem;
	a = ac - 1;
	ret = psw->sb.stack[a];
	if (index == a)
		index = 0;
	else
		index++;
	while (a > 0)
	{
		psw->sb.stack[a] = psw->sb.stack[a - 1];
		a--;
	}
	psw->sb.stack[0] = ret;
	if (bol == 1)
		ft_putendl_fd("rrb", 1);
	return (index);
}

void	ps_revrotate_r(t_psw *psw, int *index_a, int *index_b)
{
	*index_a = ps_revrotate_a(psw, *index_a, 0);
	*index_b = ps_revrotate_b(psw, *index_b, 0);
	ft_putendl_fd("rrr", 1);
}
