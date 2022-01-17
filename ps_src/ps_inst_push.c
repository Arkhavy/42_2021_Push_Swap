/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:27:39 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/11 10:26:47 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_inc/push_swap.h"

void	ps_push_a(t_psw *psw)
{
	int	a;
	int	ac_a;
	int	ac_b;

	a = 0;
	ac_a = psw->sa.nb_elem;
	ac_b = psw->sb.nb_elem;
	while (ac_a > 0)
	{
		psw->sa.stack[ac_a] = psw->sa.stack[ac_a - 1];
		ac_a--;
	}
	psw->sa.stack[0] = psw->sb.stack[0];
	while (a < ac_b)
	{
		psw->sb.stack[a] = psw->sb.stack[a + 1];
		a++;
	}
	psw->sb.stack[a] = 0;
	psw->sb.nb_elem--;
	psw->sa.nb_elem++;
	ft_putendl_fd("pa", 1);
}

void	ps_push_b(t_psw *psw)
{
	int	a;
	int	ac_a;
	int	ac_b;

	a = 0;
	ac_a = psw->sa.nb_elem;
	ac_b = psw->sb.nb_elem;
	while (ac_b > 0)
	{
		psw->sb.stack[ac_b] = psw->sb.stack[ac_b - 1];
		ac_b--;
	}
	psw->sb.stack[0] = psw->sa.stack[0];
	while (a < ac_a)
	{
		psw->sa.stack[a] = psw->sa.stack[a + 1];
		a++;
	}
	psw->sa.stack[a] = 0;
	psw->sa.nb_elem--;
	psw->sb.nb_elem++;
	ft_putendl_fd("pb", 1);
}
