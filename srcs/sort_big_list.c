/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:26:04 by hipham            #+#    #+#             */
/*   Updated: 2024/06/14 16:37:28 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_size_100(t_ilist **list_a, t_ilist **list_b)
{
	int	size_a;
	int	size_b;

	size_a = list_size(*list_a);
	while (list_size(*list_a) > size_a / 5)
		split_list_a(list_a, list_b);
	size_b = list_size(*list_b);
	sort_small_list(list_a, list_b);
	while (list_size(*list_b) - 1 > size_b)
		push_it(list_b, list_a, 'a');
	sort_reverse_small_list(list_b, list_a);
	while (list_size(*list_b) > 0)
		push_it(list_b, list_a, 'a');
}

void	sort_size_500(t_ilist **list_a, t_ilist **list_b)
{
	int	size_a;
	int	size_b;
	int	size;

	size = list_size(*list_a);
	while (list_size(*list_a) > size / 5)
		split_list_a(list_a, list_b);
	size_b = list_size(*list_b);
	sort_small_list(list_a, list_b);
	while (list_size(*list_b) - 1 > size_b)
		push_it(list_b, list_a, 'a');
	size_b = list_size(*list_b);
	size_a = list_size(*list_a);
	while (list_size(*list_b) > size_b / 5)
		split_list_b(list_b, list_a);
	sort_reverse_small_list(list_b, list_a);
	while (list_size(*list_a) - 1 > size_a)
		push_it(list_a, list_b, 'b');
	sort_reverse_small_list(list_b, list_a);
}
