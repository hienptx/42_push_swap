/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:28:58 by hipham            #+#    #+#             */
/*   Updated: 2024/06/10 17:14:31 by hipham           ###   ########.fr       */
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
	long			*a;
	long				*b;
	struct n_list	*next;
}					t_ilist;

//arg_handling.c
void				handling_invalid_input(char **s, t_ilist *list);
int					check_duplicates(t_ilist *list);
int					str_arg_handling(char *s);
int					num_arg_handling(int ac, char **ag);

// linked_list_utils.c
void				ft_freelst(t_ilist *list);
void				print_list(t_ilist *list);
int					list_size(t_ilist *list);
void				lst_delone(t_ilist *lst, void (*del)(void *));
void				del(void *data);

// make_list.c
t_ilist				*list_new(void *content);
void				list_add_front(t_ilist **lst, t_ilist *new);
t_ilist				*append_to_lst(t_ilist *list, long int nbr);
t_ilist				*check_and_add(long int num, t_ilist *list, char **s);
t_ilist				*make_list(int ac, char **ag, t_ilist *list);

//push_swap_utils.c
int					compare(int a, int b);
void				swap_int(int *val1, int *val2);
void				err_message(int n);

// push_swap.c
int					arg_handling(int ac, char **ag);
int					ascending_sorted(t_ilist *stack_a);

// sort_instruction.c
void				swap_it(t_ilist **list, char name);
void				ss(t_ilist **stack_a, t_ilist **stack_b);
void				rotate_it(t_ilist **list, char name);
void				reverse_rotate(t_ilist **list, char name);
void				push_it(t_ilist **stack_a, t_ilist **stack_b, char name);

// sort_instruction_utils.c
void				sa_pb(t_ilist **list_a, t_ilist **list_b);
void				sb_pa(t_ilist **list_a, t_ilist **list_b);
void				sa_pa(t_ilist **list_a, t_ilist **list_b);
int					get_min(t_ilist *list);
int	 				get_max(t_ilist *list);


// sort_small_list.c
void				sort_size_3(t_ilist **list_a, t_ilist **list_b);
void				sort_small_list(t_ilist **list_a, t_ilist **list_b);
void				sort_big_list(t_ilist **list_a, t_ilist **list_b);
// int					get_max_index(t_ilist *list);
int					get_min_index(t_ilist *list);

#endif