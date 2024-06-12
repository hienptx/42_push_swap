/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:05:43 by hipham            #+#    #+#             */
/*   Updated: 2024/06/12 18:28:26 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare(int a, int b)
{
	return (a > b);
}

void	swap_int(long *val1, long *val2)
{
	int	tmp;

	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

void	err_message(int n)
{
	if (n == 0)
		ft_printf("Error\n");
	if (n == 1)
		ft_printf("Error\n");
	if (n == -1)
		ft_printf("Error\n");
	if (n == -2)
	{
		ft_printf("Error\n");
		return ;
	}
	exit(EXIT_FAILURE);
}

int	get_max_index(t_ilist *list)
{
	int		id;
	t_ilist	*tmp;
	int		max;

	tmp = list;
	max = *tmp->a;
	tmp = tmp->next;
	id = -1;
	while (tmp != NULL)
	{
		if (*tmp->a > max)
			max = *tmp->a;
		tmp = tmp->next;
	}
	tmp = list;
	while (tmp != NULL)
	{
		id++;
		if (*tmp->a == max)
			return (id);
		tmp = tmp->next;
	}
	return (id);
}

int	get_min_index(t_ilist *list)
{
	int		id;
	t_ilist	*tmp;
	int		min;

	tmp = list;
	min = *tmp->a;
	tmp = tmp->next;
	id = -1;
	while (tmp != NULL)
	{
		if (*tmp->a < min)
			min = *tmp->a;
		tmp = tmp->next;
	}
	tmp = list;
	while (tmp != NULL)
	{
		id++;
		if (*tmp->a == min)
			return (id);
		tmp = tmp->next;
	}
	return (id);
}
