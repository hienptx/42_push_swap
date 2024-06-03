/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:28:58 by hipham            #+#    #+#             */
/*   Updated: 2024/06/03 21:26:33 by hipham           ###   ########.fr       */
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
void		make_list(int ac, char **ag);

int 		check_validation(long int num);
void		ft_freelst(t_list *list);
void		err_message(int n);
void		handling_invalid_input(char **s, t_list *list);

#endif