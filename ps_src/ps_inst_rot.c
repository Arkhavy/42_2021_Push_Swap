/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:09:40 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/11 10:15:20 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_inc/push_swap.h"

int	ps_rotate_a(t_psw *psw, int index, int bol)
{
	int	a;
	int	ret;
	int	ac;

	ac = psw->sa.nb_elem - 1;
	a = 0;
	ret = psw->sa.stack[0];
	if (index == 0)
		index = ac;
	else
		index--;
	while (a < ac)
	{
		psw->sa.stack[a] = psw->sa.stack[a + 1];
		a++;
	}
	psw->sa.stack[a] = ret;
	if (bol == 1)
		ft_putendl_fd("ra", 1);
	return (index);
}

int	ps_rotate_b(t_psw *psw, int index, int bol)
{
	int	a;
	int	ret;
	int	ac;

	ac = psw->sb.nb_elem - 1;
	a = 0;
	ret = psw->sb.stack[0];
	if (index == 0)
		index = ac;
	else
		index--;
	while (a < ac)
	{
		psw->sb.stack[a] = psw->sb.stack[a + 1];
		a++;
	}
	psw->sb.stack[a] = ret;
	if (bol == 1)
		ft_putendl_fd("rb", 1);
	return (index);
}

void	ps_rotate_r(t_psw *psw, int *index_a, int *index_b)
{
	*index_a = ps_rotate_a(psw, *index_a, 0);
	*index_b = ps_rotate_b(psw, *index_b, 0);
	ft_putendl_fd("rr", 1);
}
