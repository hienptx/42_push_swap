/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:16 by hipham            #+#    #+#             */
/*   Updated: 2024/06/10 21:15:19 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	descending_sorted(t_ilist *stack_a)
// {
// 	t_ilist	*tmp;

// 	tmp = stack_a;
// 	while (tmp->next != NULL)
// 	{
// 		if (*(int *)tmp->a > *(int *)tmp->next->a)
// 			tmp = tmp->next;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

t_ilist	*sort_list(t_ilist *list_a, t_ilist *list_b)
{
	int	size;

	size = list_size(list_a);
	if (size <= 1)
		return (list_a);
	if (size == 2 && compare(*(int *)list_a->a, *(int *)list_a->next->a))
		swap_it(&list_a, 'a');
	if (size == 3)
		sort_size_3(&list_a, &list_b);
	if (size <= 10)
		sort_small_list(&list_a, &list_b);
	// if (size > 10)
	// 	sort_big_list(&list_a, &list_b);

	return (list_a);
}

int	ascending_sorted(t_ilist *stack_a)
{
	t_ilist	*tmp;

	tmp = stack_a;
	while (tmp->next != NULL)
	{
		if (*(int *)tmp->a < *(int *)tmp->next->a)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	arg_handling(int ac, char **ag)
{
	if (ac == 2)
	{
		if (!str_arg_handling(ag[1]))
			return (0);
		else
			return (1);
	}
	else
	{
		if (!num_arg_handling(ac, ag))
			return (0);
		else
			return (1);
	}
}

int	main(int ac, char **ag)
{
	t_ilist	*list_a;
	t_ilist	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (ac < 2)
		err_message(0);
	if (arg_handling(ac, ag) == 0)
		err_message(1);
	else
		list_a = make_list(ac, ag, list_a);
	if (!check_duplicates(list_a))
		handling_invalid_input(NULL, list_a);
	if (ascending_sorted(list_a))
	{
		ft_freelst(list_a);
		exit(EXIT_SUCCESS);
	}
	list_a = sort_list(list_a, list_b);
	ft_printf("Sorted list: \n");
	print_list(list_a);
	ft_freelst(list_a);
	ft_freelst(list_b);
	exit(EXIT_SUCCESS);
}
