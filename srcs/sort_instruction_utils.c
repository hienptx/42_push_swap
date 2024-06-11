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
	if ((*((*list_a)->a)) > (*(*list_a)->next->a))
		swap_it(list_a, 'a');
	push_it(list_a, list_b, 'b');
}

void	sa_pa(t_ilist **list_a, t_ilist **list_b)
{
	if ((*((*list_a)->a)) > (*(*list_a)->next->a))
		swap_it(list_a, 'a');
	push_it(list_b, list_a, 'a');
}

void	sb_pa(t_ilist **list_a, t_ilist **list_b)
{
	if ((*((*list_b)->a)) < (*(*list_b)->next->a))
		swap_it(list_b, 'b');
	push_it(list_b, list_a, 'a');
}

int get_min(t_ilist *list)
{
	int min;
	t_ilist *tmp;
	
	tmp = list;
	min = *tmp->a;
	while (tmp != NULL)
	{
		if (*tmp->a < min)
			min = *tmp->a;
		tmp = tmp->next;
	}
	return(min);
}

int get_max(t_ilist *list)
{
	int max;
	t_ilist *tmp;
	
	tmp = list;
	max = *tmp->a;
	while (tmp != NULL)
	{
		if (*tmp->a > max)
			max = *tmp->a;
		tmp = tmp->next;
	}
	return(max);
}
