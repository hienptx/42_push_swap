/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:05:43 by hipham            #+#    #+#             */
/*   Updated: 2024/06/05 17:30:13 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int compare(int a, int b)
{
	return(a > b);
}

void	swap_int(int *val1, int *val2)
{
	int	tmp;

	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

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
