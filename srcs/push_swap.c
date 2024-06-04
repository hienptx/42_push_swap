/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:16 by hipham            #+#    #+#             */
/*   Updated: 2024/06/04 20:42:52 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_message(int n)
{
	if (n == 0)
		ft_printf("Error: Missing Arguments\n");
	if (n == 1)
		ft_printf("Error: Invalid Arguments\n");
	if (n == -1)
		ft_printf("Error: Malloc failed");
	exit(EXIT_FAILURE);
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
	t_list	*list;

	list = NULL;
	if (ac < 2)
		err_message(0);
	if (arg_handling(ac, ag) == 0)
		err_message(1);
	else
		list = make_list(ac, ag, list);
	ft_printf("Before swap = \n");
	print_list(list);
	swap_a(list);
	ft_freelst(list);
	exit(EXIT_SUCCESS);
}
