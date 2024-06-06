/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:20 by hipham            #+#    #+#             */
/*   Updated: 2024/06/06 21:49:50 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	swap_a(i_list **list)
{
	i_list	*tmp;

	tmp = *list;
	if (list_size(tmp) < 2)
		;
	else
		swap_int((int *)tmp->a, (int *)tmp->next->a);
}

void	swap_b(i_list **list)
{
	i_list	*tmp;

	tmp = *list;
	if (list_size(tmp) < 2)
		;
	else
		swap_int((int *)tmp->b, (int *)tmp->next->b);
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate_a(i_list **list)
{
	i_list	*first;

	first = *list;
	*list = append_to_lst(*list, *(long int *)first->a);
	*list = first->next;
	lst_delone(first, del);
}

// pa (push a): Take the first element at the top of b
// and put it at the top of a. Do nothing if b is empty.
void	push_b(i_list **stack_a, i_list **stack_b)
{
	i_list	*tmp;
	i_list	*head;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	tmp = *stack_a;
	if (*stack_b == NULL)
	{
		*stack_b = append_to_lst(*stack_b, *(int *)(*stack_a)->a);
		if (tmp->a != NULL)
			free(tmp->a);
	}
	else
	{
		head = list_new(tmp->b);
		if (head == NULL)
		{
			ft_printf("Malloc failed");
			return ;
		}
		list_add_front(stack_b, head);
	}
	*stack_a = tmp->next;
	free(tmp);
}

void	push_a(i_list **stack_a, i_list **stack_b)
{
	i_list	*tmp;
	i_list	*head;

	ft_printf("pa\n");
	if (stack_b == NULL || *stack_b == NULL)
		return ;
	tmp = *stack_b;
	if (*stack_a == NULL)
	{
		*stack_a = append_to_lst(*stack_a, *(int *)(*stack_a)->b);
		if (tmp->b != NULL)
			free(tmp->b);
	}
	else
	{
		head = list_new(tmp->a);
		if (head == NULL)
		{
			ft_printf("Malloc failed");
			return ;
		}
		list_add_front(stack_a, head);
	}
	*stack_b = tmp->next;
	free(tmp);
}
