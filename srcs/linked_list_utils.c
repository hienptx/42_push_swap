/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:44:51 by hipham            #+#    #+#             */
/*   Updated: 2024/06/07 15:12:26 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freelst(t_ilist *list)
{
	t_ilist	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp->a);
		free(tmp);
	}
}

void	print_list(t_ilist *list)
{
	t_ilist	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_printf("%d\n", *(long int *)tmp->a);
		tmp = tmp->next;
	}
}

int	list_size(t_ilist *list)
{
	int		i;
	t_ilist	*tmp;

	i = 0;
	tmp = list;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	lst_delone(t_ilist *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		;
	del(lst->a);
	free(lst);
}

void	del(void *data)
{
	free(data);
}
