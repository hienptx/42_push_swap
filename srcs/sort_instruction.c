/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:20 by hipham            #+#    #+#             */
/*   Updated: 2024/06/10 21:11:05 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	swap_it(t_ilist **list, char name)
{
	t_ilist	*tmp;

	tmp = *list;
	if (list_size(tmp) < 2)
		;
	else
	{
		swap_int(tmp->a, tmp->next->a);
		ft_printf("s%c\n", name);
	}
}

void	ss(t_ilist **stack_a, t_ilist **stack_b)
{
	t_ilist	*tmp;
	t_ilist	*tmp1;

	tmp = *stack_a;
	tmp1 = *stack_b;
	if (list_size(tmp) < 2)
		;
	else
		swap_int(tmp->a, tmp->next->a);
	if (list_size(tmp1) < 2)
		;
	else
		swap_int(tmp1->a, tmp1->next->a);
	ft_printf("ss\n");
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate_it(t_ilist **list, char name)
{
	t_ilist	*first;

	first = *list;
	*list = append_to_lst(*list, *first->a);
	*list = first->next;
	lst_delone(first, del);
	ft_printf("r%c\n", name);
}

void	reverse_rotate(t_ilist **list, char name)
{
	t_ilist	*last;
	t_ilist	*second_last;

	if (!list || !*list || !(*list)->next)
		return ;
	last = *list;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *list;
	*list = last;
	ft_printf("rr%c\n", name);
}

// pa (push a): Take the first element at the top of b
// and put it at the top of a. Do nothing if b is empty.

void	push_it(t_ilist **stack_a, t_ilist **stack_b, char name)
{
	t_ilist	*tmp;
	t_ilist	*head;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	tmp = *stack_a;
	if (*stack_b == NULL)
	{
		*stack_b = append_to_lst(*stack_b, *(*stack_a)->a);
		if (tmp->a != NULL)
			free(tmp->a);
	}
	else
	{
		head = list_new(tmp->a);
		if (head == NULL)
			err_message(-2);
		list_add_front(stack_b, head);
	}
	*stack_a = tmp->next;
	ft_printf("p%c\n", name);
	free(tmp);
}
