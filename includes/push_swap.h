/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:28:58 by hipham            #+#    #+#             */
/*   Updated: 2024/06/05 16:03:49 by hipham           ###   ########.fr       */
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

typedef struct n_list
{
	void			*a;
	void			*b;
	struct n_list	*next;
}					i_list;

int			arg_handling(int ac, char **ag);
int			num_arg_handling(int ac, char **ag);
int			str_arg_handling(char *s);

i_list		*check_and_add(long int num, i_list *list, char **s);
void		handling_invalid_input(char **s, i_list *list);
int			check_duplicates(i_list *list);

i_list		*make_list(int ac, char **ag, i_list *list);
i_list		*append_to_lst(i_list *list, long int nbr);
void		print_list(i_list *list);

void		ft_freelst(i_list *list);
void		err_message(int n);
int			list_size(i_list *list);

void		swap_int(int *val1, int *val2);
void		swap_a(i_list *list);
int			compare(int a, int b);

#endif