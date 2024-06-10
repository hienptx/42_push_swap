/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instruction_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:10:34 by hipham            #+#    #+#             */
/*   Updated: 2024/06/10 21:10:44 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_pb(t_ilist **list_a, t_ilist **list_b)
{
	if ((*(int *)((*list_a)->a)) > (*(int *)(*list_a)->next->a))
		swap_it(list_a, 'a');
	push_it(list_a, list_b, 'b');
}

void	sa_pa(t_ilist **list_a, t_ilist **list_b)
{
	if ((*(int *)((*list_a)->a)) > (*(int *)(*list_a)->next->a))
		swap_it(list_a, 'a');
	push_it(list_b, list_a, 'a');
}

void	sb_pa(t_ilist **list_a, t_ilist **list_b)
{
	if ((*(int *)((*list_b)->a)) < (*(int *)(*list_b)->next->a))
		swap_it(list_b, 'b');
	push_it(list_b, list_a, 'a');
}
