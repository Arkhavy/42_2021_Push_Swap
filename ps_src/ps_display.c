/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:15:40 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/11 11:33:26 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_inc/push_swap.h"

void	ps_display(t_psw psw)
{
	static size_t	roll;
	size_t			sleep;
	int				a;

	a = 0;
	dprintf(1, "roll = %zu\nA : ", roll);
	while (a < psw.sa.nb_elem)
	{
		dprintf(1, "%d | ", psw.sa.stack[a]);
		a++;
	}
	a = 0;
	dprintf(1, "\nB : ");
	while (a < psw.sb.nb_elem)
	{
		dprintf(1, "%d | ", psw.sb.stack[a]);
		a++;
	}
	dprintf(1, "\n");
	sleep = 0;
	while (sleep < 500000000)
		sleep++;
	roll++;
}
