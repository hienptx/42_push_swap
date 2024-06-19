/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instruction_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:10:34 by hipham            #+#    #+#             */
/*   Updated: 2024/06/17 19:17:48 by hipham           ###   ########.fr       */
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

void	rr(t_ilist **list_a, t_ilist **list_b)
{
	t_ilist	*tmp_a;
	t_ilist	*tmp_b;

	tmp_a = *list_a;
	*list_a = append_to_lst(*list_a, *tmp_a->a);
	*list_a = tmp_a->next;
	lst_delone(tmp_a, del);
	tmp_b = *list_b;
	*list_b = append_to_lst(*list_b, *tmp_b->a);
	*list_b = tmp_b->next;
	lst_delone(tmp_b, del);
	ft_printf("rr\n");
}
