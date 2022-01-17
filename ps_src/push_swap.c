/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:49:02 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/11 17:38:32 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_inc/push_swap.h"

static void	ps_free(t_psw *psw)
{
	free (psw->sa.stack);
	free (psw->sb.stack);
}

static int	ps_check_av(char *av)
{
	size_t	a;

	a = 0;
	while (av[a])
	{
		if (!ft_isdigit(av[a]))
		{
			if (av[a] != '-' && av[a] != '+')
				return (0);
		}
		a++;
	}
	return (1);
}

static int	ps_check_error(char **av)
{
	size_t	a;
	size_t	b;
	long	res;

	a = 1;
	res = ft_atoi(av[a]);
	while (av[a])
	{
		if (av[a][0] == '\0' || !ps_check_av(av[a]))
			return (write (2, "Error\n", 6) * 0);
		res = ft_atoi(av[a]);
		if (ft_atol(av[a]) > INT_MAX || ft_atol(av[a]) < INT_MIN)
			return (write (2, "Error\n", 6) * 0);
		b = 1;
		while (b < a)
		{
			if (res == ft_atoi(av[b]))
				return (write (2, "Error\n", 6) * 0);
			b++;
		}
		a++;
	}
	return (1);
}

static int	*ps_init_ranks(int *stack, int ac)
{
	int	a;
	int	b;
	int	*newstack;
	int	rank;

	a = 0;
	newstack = malloc(sizeof(int) * (ac + 1));
	if (!newstack)
		return (NULL);
	while (a < ac)
	{
		b = 0;
		rank = 1;
		while (b < ac)
		{
			if (stack[a] > stack[b])
				rank++;
			b++;
		}
		newstack[a] = rank;
		a++;
	}
	newstack[a] = 0;
	free (stack);
	return (newstack);
}

int	main(int ac, char **av)
{
	t_psw	psw;
	int		a;

	a = 1;
	psw.sa.stack = malloc(sizeof(int) * ac);
	psw.sb.stack = malloc(sizeof(int) * ac);
	if (!psw.sa.stack || !psw.sb.stack || ac <= 2 || !ps_check_error(av))
	{
		ps_free(&psw);
		return (0);
	}
	while (a < ac)
	{
		psw.sa.stack[a - 1] = ft_atoi(av[a]);
		psw.sb.stack[a - 1] = 0;
		a++;
	}
	psw.ac = ac - 1;
	psw.sa.stack = ps_init_ranks(psw.sa.stack, psw.ac);
	psw.sb.stack[a - 1] = 0;
	psw.sa.nb_elem = ac - 1;
	psw.sb.nb_elem = 0;
	push_swap(psw);
	ps_free(&psw);
	return (0);
}
