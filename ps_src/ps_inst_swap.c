/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:21:20 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/11 09:27:24 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_inc/push_swap.h"

void	ps_swap_a(t_psw *psw)
{
	int	ret;

	ret = psw->sa.stack[0];
	psw->sa.stack[0] = psw->sa.stack[1];
	psw->sa.stack[1] = ret;
	ft_putendl_fd("sa", 1);
}

void	ps_swap_b(t_psw *psw)
{
	int	ret;

	ret = psw->sb.stack[0];
	psw->sb.stack[0] = psw->sb.stack[1];
	psw->sb.stack[1] = ret;
	ft_putendl_fd("sb", 1);
}

void	ps_swap_s(t_psw *psw)
{
	int	ret_a;
	int	ret_b;

	ret_a = psw->sa.stack[0];
	ret_b = psw->sb.stack[0];
	psw->sa.stack[0] = psw->sa.stack[1];
	psw->sa.stack[1] = ret_a;
	psw->sb.stack[0] = psw->sb.stack[1];
	psw->sb.stack[1] = ret_b;
	ft_putendl_fd("ss", 1);
}
