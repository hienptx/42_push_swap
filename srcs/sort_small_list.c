/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:42:39 by hipham            #+#    #+#             */
/*   Updated: 2024/06/19 16:26:42 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void	split_list_a(t_ilist **list_a, t_ilist **list_b)
{
	int		size;
	long	avrg;

	size = list_size(*list_a);
	avrg = (get_min(*list_a) + get_max(*list_a)) / 2;
	size = list_size(*list_a);
	while (size-- > 0)
	{
		if (*(*list_a)->a < avrg)
			push_it(list_a, list_b, 'b');
		else
			rotate_it(list_a, 'a');
	}
}

void	split_list_b(t_ilist **list_b, t_ilist **list_a)
{
	int		size;
	long	avrg;

	size = list_size(*list_b);
	avrg = (get_min(*list_b) + get_max(*list_b)) / 2;
	size = list_size(*list_b);
	while (size-- > 0)
	{
		if (*(*list_b)->a > avrg)
			push_it(list_b, list_a, 'a');
		else
			rotate_it(list_b, 'b');
	}
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
