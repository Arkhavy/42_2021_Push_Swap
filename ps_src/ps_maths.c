/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:53:16 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/11 12:53:33 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_inc/push_swap.h"

int	ps_get_sqrt(int nb_elem)
{
	int	a;

	a = 0;
	while (a * a < nb_elem)
		a++;
	return (a);
}

int	ps_get_nb_packs(int nb_elem)
{
	return (ps_get_sqrt(nb_elem) / 2);
}

int	ps_get_sizeof_packs(int nb_elem)
{
	return (nb_elem / ps_get_nb_packs(nb_elem));
}
