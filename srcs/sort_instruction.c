/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:20 by hipham            #+#    #+#             */
/*   Updated: 2024/06/04 20:44:21 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *val1, int *val2)
{
	int	tmp;

	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

void	swap_a(t_list *list)
{
	t_list	*tmp;

    tmp = list;
	ft_swap((int *)tmp->content, (int *)tmp->next->content);
    ft_printf("After swap = \n");
    print_list(list);
}
