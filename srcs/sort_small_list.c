/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:42:39 by hipham            #+#    #+#             */
/*   Updated: 2024/06/10 21:12:58 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_ilist *list)
{
	int		id;
	t_ilist	*tmp;
	int max;

	tmp = list;
	max = *tmp->a;
	tmp = tmp->next;
	id = -1;
	while (tmp != NULL)
	{
		if (*tmp->a > max)
			max = *tmp->a;
		tmp = tmp->next;
	}
	tmp = list;
	while (tmp != NULL)
	{
		id++;
		if (*tmp->a == max)
			return (id);
		tmp = tmp->next;
	}
	return (id);
}

int	get_min_index(t_ilist *list)
{
	int		id;
	t_ilist	*tmp;
	int min;

	tmp = list;
	min = *tmp->a;
	tmp = tmp->next;
	id = -1;
	while (tmp != NULL)
	{
		if (*tmp->a < min)
			min = *tmp->a;
		tmp = tmp->next;
	}
	tmp = list;
	while (tmp != NULL)
	{
		id++;
		if (*tmp->a == min)
			return (id);
		tmp = tmp->next;
	}
	return (id);
}

void	sort_size_3(t_ilist **list_a, t_ilist **list_b)
{
	int	min_id;

	if (ascending_sorted(*list_a))
		return ;
	min_id = get_min_index(*list_a);
	if (min_id == 0)
	{
		push_it(list_a, list_b, 'b');
		if ((*((*list_a)->a)) > (*(*list_a)->next->a))
			swap_it(list_a, 'a');
		push_it(list_b, list_a, 'a');
	}
	if (min_id == 1)
	{
		if (*(*list_a)->a > *(*list_a)->next->next->a)
			rotate_it(list_a, 'a');
		else
			swap_it(list_a, 'a');
	}
	if (min_id == 2)
	{
		if ((*((*list_a)->a)) > (*(*list_a)->next->a))
			swap_it(list_a, 'a');
		reverse_rotate(list_a, 'a');
	}
}

void	sort_small_list(t_ilist **list_a, t_ilist **list_b)
{
	int	min_id;
	int	size;

	size = list_size(*list_a);
	while (size > 3)
	{
		min_id = get_min_index(*list_a);
		if (min_id > size / 2)
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
		size = list_size(*list_a);
	}
	sort_size_3(list_a, list_b);
	// while (list_size(*list_b) > 0)
	// 	push_it(list_b, list_a, 'a');
}

void	sort_reverse_small_list(t_ilist **list_b, t_ilist **list_a)
{
	int	max_id;
	int	size;

	size = list_size(*list_b);
	while (size > 0)
	{
		max_id = get_max_index(*list_b);
		if (max_id > size / 2)
		{
			while (max_id++ < size)
				reverse_rotate(list_b, 'b');
		}
		else
		{
			while (max_id-- > 0)
				rotate_it(list_b, 'b');
		}
		push_it(list_b, list_a, 'a');
		size = list_size(*list_b);
	}
	// sort_size_3(list_a, list_b);
	// while (list_size(*list_b) > 0)
	// 	push_it(list_b, list_a, 'a');
}

void	sort_big_list(t_ilist **list_a, t_ilist **list_b)
{
	int min;
	int max;
	int size;
	int avrg;
	t_ilist *tmp;
	int first;
	int store;

	first = 1;
	tmp = *list_a;
	min = get_min(*list_a);
	max = get_max(*list_a);
	avrg = (min + max) / 2;
	size = list_size(*list_a);
	while (--size > 0)
	{
		if (*tmp->a <= avrg)
			push_it(list_a, list_b, 'b');
		else
			rotate_it(list_a, 'a');
		tmp = *list_a;
	}
	size = list_size(*list_a);
	int size_b = list_size(*list_b);
	if (first)
		store = size_b;
	first = 0;
	if (size > 50)
		sort_big_list(list_a, list_b);
	sort_small_list(list_a, list_b);
	while (list_size(*list_b) - 1 > store)
		push_it(list_b, list_a, 'a');
	sort_reverse_small_list(list_b, list_a);
	// sort_size_3(list_b, list_a);
	while (list_size(*list_b) > 0)
		push_it(list_b, list_a, 'a');
	// ft_printf("size of b = %i\n", list_size(*list_b));
	// ft_printf("list b\n");
}


// void	sort_small_list(t_ilist **list_a, t_ilist **list_b)
// {
// 	int min_id;
// 	int size;

// 	size = list_size(*list_a);
// 	min_id = get_min_index(*list_a);
// 	if(min_id > size/2)
// 	{
// 		while (min_id++ < size)
// 			reverse_rotate(list_a, 'a');
// 	}
// 	else
// 	{
// 		while (min_id-- > 0)
// 			rotate_it(list_a, 'a');
// 	}
// 	push_it(list_a, list_b, 'b');
// 	if (--size > 3)
// 		sort_small_list(list_a, list_b);
// 	sort_size_3(list_a, list_b);
// 	push_it(list_b, list_a, 'a');
// 	push_it(list_b, list_a, 'a');
// }
