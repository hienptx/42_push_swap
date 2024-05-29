/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:16 by hipham            #+#    #+#             */
/*   Updated: 2024/05/29 19:50:20 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_message(int ac)
{
	if (ac < 2)
		ft_printf("Error: Missing Arguments\n");
	if (ac >= 2)
		ft_printf("Erro: Invalid Arguments\n");
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **ag)
{
	if (ac < 2)
		err_message(ac);
	if (arg_handling(ac, ag) == 0)
	{
		ft_printf("number of integers = %i\n", arg_handling(ac, ag));
		err_message(ac);
	}
	else
	{
		ft_printf("number of integers = %i\n", arg_handling(ac, ag));
		ft_printf("%s\n", "test output");
		// make_list(ac, ag);
	}
	exit(EXIT_SUCCESS);
}
