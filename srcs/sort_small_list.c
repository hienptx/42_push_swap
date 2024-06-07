/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:42:39 by hipham            #+#    #+#             */
/*   Updated: 2024/06/07 18:18:42 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_pb(t_ilist **list_a, t_ilist **list_b)
{
	if ((*(int *)((*list_a)->a)) > (*(int *)(*list_a)->next->a))
	{
		swap_a(list_a);
		push_b(list_a, list_b);
	}
	else
		push_b(list_a, list_b);
}

void	sa_pa(t_ilist **list_a, t_ilist **list_b)
{
	if ((*(int *)((*list_a)->a)) > (*(int *)(*list_a)->next->a))
	{
		swap_a(list_a);
		push_a(list_a, list_b);
	}
	else
		push_a(list_a, list_b);
}

void	sort_size_3(t_ilist **list_a, t_ilist **list_b)
{
	sa_pb(list_a, list_b);
	sa_pa(list_a, list_b);
	if (*(int *)(*list_a)->a > *(int *)(*list_a)->next->a)
		swap_a(list_a);
}

void	sort_size_4(t_ilist **list_a, t_ilist **list_b)
{
	sa_pb(list_a, list_b);
	sa_pb(list_a, list_b);
	if ((*(int *)((*list_a)->a)) > (*(int *)(*list_a)->next->a))
	{
		if ((*(int *)((*list_b)->a)) > (*(int *)(*list_b)->next->a))
			swap_a(list_a);
		else
			ss(list_a, list_b);
		push_a(list_a, list_b);
	}
	else
	{
		if ((*(int *)((*list_b)->a)) > (*(int *)(*list_b)->next->a))
			push_a(list_a, list_b);
		else
			swap_b(list_b);
		push_a(list_a, list_b);
	}
	if ((*(int *)((*list_a)->a)) > (*(int *)(*list_a)->next->a))
		sa_pa(list_a, list_b);
	else
		push_a(list_a, list_b);
	if (*(int *)(*list_a)->a > *(int *)(*list_a)->next->a)
		swap_a(list_a);
}
