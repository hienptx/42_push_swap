/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:16 by hipham            #+#    #+#             */
/*   Updated: 2024/06/03 21:24:39 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_message(int n)
{
	if (n == 0)
		ft_printf("Error: Missing Arguments\n");
	if (n == 1)
		ft_printf("Erro: Invalid Arguments\n");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **ag)
{
	if (ac < 2)
		err_message(0);
	if (arg_handling(ac, ag) == 0)
		err_message(1);
	else
	{
		ft_printf("%s\n", "test output");
		make_list(ac, ag);
	}
	exit(EXIT_SUCCESS);
}
