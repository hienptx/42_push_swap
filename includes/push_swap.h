/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:28:58 by hipham            #+#    #+#             */
/*   Updated: 2024/06/07 17:29:57 by hipham           ###   ########.fr       */
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
}					t_ilist;

int					arg_handling(int ac, char **ag);
int					num_arg_handling(int ac, char **ag);
int					str_arg_handling(char *s);

t_ilist				*check_and_add(long int num, t_ilist *list, char **s);
void				handling_invalid_input(char **s, t_ilist *list);
int					check_duplicates(t_ilist *list);
void				err_message(int n);

t_ilist				*make_list(int ac, char **ag, t_ilist *list);
t_ilist				*append_to_lst(t_ilist *list, long int nbr);
void				list_add_front(t_ilist **lst, t_ilist *new);
t_ilist				*list_new(void *content);

void				print_list(t_ilist *list);
void				ft_freelst(t_ilist *list);
int					list_size(t_ilist *list);
void				lst_delone(t_ilist *lst, void (*del)(void *));
void				del(void *data);

void				swap_int(int *val1, int *val2);
void				swap_a(t_ilist **list);
int					compare(int a, int b);
void				rotate_a(t_ilist **list);
void				push_a(t_ilist **stack_a, t_ilist **stack_b);

void				push_b(t_ilist **stack_a, t_ilist **stack_b);
void				swap_b(t_ilist **list);
void				ss(t_ilist **stack_a, t_ilist **stack_b);

void				sort_size_3(t_ilist **list_a, t_ilist **list_b);
void				sort_size_4(t_ilist **list_a, t_ilist **list_b);

#endif