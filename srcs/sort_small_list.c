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

int get_min_index(t_ilist *list)
{
	int min;
	int id;
	t_ilist *tmp;

	tmp = list;
	min = *(int *)tmp->a;
	tmp = tmp->next;
	id = -1;
	while (tmp != NULL)
	{
		if (*(int *)tmp->a < min)
			min = *(int *)tmp->a;
		tmp = tmp->next;
	}
	tmp = list;
	while (tmp != NULL)
	{
		id++;
		if(*(int *)tmp->a == min)
			return (id);
		tmp = tmp->next;
	}
	return (id);
}

void	sort_size_3(t_ilist **list_a, t_ilist **list_b)
{
	sa_pb(list_a, list_b);
	sa_pa(list_a, list_b);
	if (*(int *)(*list_a)->a > *(int *)(*list_a)->next->a)
		swap_it(list_a, 'a');
}

void	sort_size_4(t_ilist **list_a, t_ilist **list_b)
{
	sa_pb(list_a, list_b);
	sa_pb(list_a, list_b);
	if ((*(int *)((*list_a)->a)) > (*(int *)(*list_a)->next->a))
	{
		if ((*(int *)((*list_b)->a)) > (*(int *)(*list_b)->next->a))
			swap_it(list_a, 'a');
		else
			ss(list_a, list_b);
		push_it(list_b, list_a, 'a');
	}
	else
		sb_pa(list_a, list_b);
	if ((*(int *)((*list_a)->a)) > (*(int *)(*list_a)->next->a))
		sa_pa(list_a, list_b);
	else
		push_it(list_b, list_a, 'a');
	if (*(int *)(*list_a)->a > *(int *)(*list_a)->next->a)
		swap_it(list_a, 'a');
}

void	sort_size_5(t_ilist **list_a, t_ilist **list_b)
{
	int min_id;
	int size; 

	size = list_size(*list_a);
	min_id = get_min_index(*list_a);
	//ft_printf("index = %i\n", min_id);
	if(min_id > size/2)
	{
		while (min_id++ < size)
			reverse_rotate(list_a, 'a');
	}
	else
	{
		while (min_id-- > 0)
			rotate_it(list_a, 'a');
	}
	push_it(list_a, list_b, 'b');
	if (--size >= 4)
		sort_size_5(list_a, list_b);
	sort_size_3(list_a, list_b);
	push_it(list_b, list_a, 'a');
	push_it(list_b, list_a, 'a');
}
