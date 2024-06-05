/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:20 by hipham            #+#    #+#             */
/*   Updated: 2024/06/05 21:07:07 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements.
void	swap_a(i_list *list)
{
	i_list	*tmp;

    tmp = list;
	if (list_size(tmp) < 2)
		;
	else
		swap_int((int *)tmp->a, (int *)tmp->next->a);
    ft_printf("After sa = \n");
    print_list(list);
}

void	swap_b(i_list *list)
{
	i_list	*tmp;

    tmp = list;
	if (list_size(tmp) < 2)
		;
	else
		swap_int((int *)tmp->b, (int *)tmp->next->b);
    ft_printf("After sb = \n");
    print_list(list);
}

void	rotate_a(i_list **list)
{
	i_list	*first;

	first = *list;
	*list = append_to_lst(*list, *(long int*)first->a);
	*list = first->next;
	lst_delone(first, del);
    ft_printf("After pa = \n");
    print_list(*list);
}
