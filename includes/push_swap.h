/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:28:58 by hipham            #+#    #+#             */
/*   Updated: 2024/05/29 19:50:05 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MIN -2147483648
# define MAX 2147483647

# include "ft_printf.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack_a
{
	int		a;
	void	*next_a;
}			t_stack_a;

typedef struct s_stack_b
{
	int		b;
	void	*next_b;
}			t_stack_b;

int			arg_handling(int ac, char **ag);
// t_list		make_list(int ac, char **s);

#endif