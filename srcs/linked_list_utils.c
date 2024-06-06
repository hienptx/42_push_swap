/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:44:51 by hipham            #+#    #+#             */
/*   Updated: 2024/06/06 21:53:03 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freelst(i_list *list)
{
	i_list	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp->a);
		free(tmp);
	}
}

void	print_list(i_list *list)
{
	i_list	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_printf("%d\n", *(long int *)tmp->a);
		tmp = tmp->next;
	}
}

int	list_size(i_list *list)
{
	int		i;
	i_list	*tmp;

	i = 0;
	tmp = list;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	lst_delone(i_list *lst, void (*del)(void *))
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
