/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:16 by hipham            #+#    #+#             */
/*   Updated: 2024/06/05 21:12:15 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

i_list *sort_list(i_list *list)
{
	int size;

	size = list_size(list);
	if (size == 1)
		return (list);
	if (size == 2 && compare(*(int *)list->a, *(int *)list->next->a))
		swap_a(list);
	if (size > 2)
		rotate_a(&list);
	return(list);
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
	i_list	*list_a;
	i_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (ac < 2)
		err_message(0);
	if (arg_handling(ac, ag) == 0)
		err_message(1);
	else
		list_a = make_list(ac, ag, list_a);
	ft_printf("Before = \n");
	print_list(list_a);
	list_a = sort_list(list_a);
	ft_freelst(list_a);
	ft_freelst(list_b);
	exit(EXIT_SUCCESS);
}
