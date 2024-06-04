/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:28:58 by hipham            #+#    #+#             */
/*   Updated: 2024/06/04 20:43:14 by hipham           ###   ########.fr       */
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
int			num_arg_handling(int ac, char **ag);
int			str_arg_handling(char *s);
t_list		*check_and_add(long int num, t_list *list, char **s);
void		handling_invalid_input(char **s, t_list *list);
int			check_duplicates(t_list *list);

t_list		*make_list(int ac, char **ag, t_list *list);
t_list		*append_to_lst(t_list *list, long int nbr);
void		print_list(t_list *list);

void		ft_freelst(t_list *list);
void		err_message(int n);

void		swap_a(t_list *list);

#endif