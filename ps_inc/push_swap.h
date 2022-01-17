/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 09:35:53 by ljohnson          #+#    #+#             */
/*   Updated: 2022/01/14 16:06:59 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/lib_includes/libft.h"
# include <stdio.h>

/*/////////////////////////////////////////////////////////////////////////////
		TYPEDEF STRUCT
*//////////////////////////////////////////////////////////////////////////////

typedef struct s_stack
{
	int	*stack;
	int	nb_elem;
}	t_stack;

typedef struct s_psw
{
	t_stack	sa;
	t_stack	sb;
	int		ac;
	int		nb_packs;
	int		size_pack;
}	t_psw;

typedef struct s_marks
{
	int	tail_low;
	int	tail_high;
	int	head_low;
	int	head_high;
}	t_mark;

/*/////////////////////////////////////////////////////////////////////////////
		ALL FUNCTIONS PER FILES
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- push_swap.c --------------------*/

//void	ps_free(t_psw *psw);
//int	ps_check_av(char *av);
//int	ps_check_error(char **av);
//int	*ps_init_ranks(int *stack, int ac);
//int	main(int ac, char **av);

/*-------------------- ps_hub.c --------------------*/

//int	ps_check_sort(t_psw psw);
void	push_swap(t_psw psw);

/*-------------------- ps_utils.c --------------------*/

int		ps_count_size(int *stack);
void	ps_rotate_index(t_psw *psw, int *index_a, int *index_b, char c);
void	ps_rotate_to_first(t_psw *psw, char c);
int		ps_find_first(t_psw *psw);
int		ps_check_a_from_start(t_psw *psw);

/*-------------------- ps_maths.c --------------------*/

int		ps_get_sqrt(int nb_elem);
int		ps_get_nb_packs(int nb_elem);
int		ps_get_sizeof_packs(int nb_elem);

/*-------------------- ps_sort_small.c --------------------*/

//void	ps_push_back(t_psw *psw);
//void	ps_sort_three(t_psw *psw);
void	ps_sort_small(t_psw *psw);

/*-------------------- ps_sort_big.c --------------------*/

//void	ps_rotate_b_to_push(t_psw *psw);
//int	ps_check_indexes(t_psw psw, int tail, int head, int loop);
//int	ps_check_current_pack(t_psw *psw, int tail, int head);
//void	ps_2pack_sort(t_psw *psw);
void	ps_sort_big(t_psw *psw);

/*-------------------- ps_display.c --------------------*/

void	ps_display(t_psw psw);

/*/////////////////////////////////////////////////////////////////////////////
		ALL INSTRUCTIONS
*//////////////////////////////////////////////////////////////////////////////

/*-------------------- ps_inst_push.c --------------------*/

void	ps_push_a(t_psw *psw);
void	ps_push_b(t_psw *psw);

/*-------------------- ps_inst_swap.c --------------------*/

void	ps_swap_a(t_psw *psw);
void	ps_swap_b(t_psw *psw);
void	ps_swap_s(t_psw *psw);

/*-------------------- ps_inst_rot.c --------------------*/

int		ps_rotate_a(t_psw *psw, int index, int bol);
int		ps_rotate_b(t_psw *psw, int index, int bol);
void	ps_rotate_r(t_psw *psw, int *index_a, int *index_b);

/*-------------------- ps_inst_revrot.c --------------------*/

int		ps_revrotate_a(t_psw *psw, int index, int bol);
int		ps_revrotate_b(t_psw *psw, int index, int bol);
void	ps_revrotate_r(t_psw *psw, int *index_a, int *index_b);

#endif