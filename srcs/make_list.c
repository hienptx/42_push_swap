/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:12 by hipham            #+#    #+#             */
/*   Updated: 2024/06/06 21:17:14 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

i_list	*list_new(void *val)
{
	i_list	*firstnode;

	firstnode = malloc(sizeof(i_list));
	if (firstnode == NULL)
		return (NULL);
	firstnode->a = val;
	firstnode->next = NULL;
	return (firstnode);
}

void	list_add_front(i_list **lst, i_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

i_list	*append_to_lst(i_list *list, long int nbr)
{
	i_list		*newnode;
	i_list		*tmp;
	long int	*n;

	n = malloc(sizeof(long int));
	if (n == NULL)
		return (NULL);
	*n = nbr;
	newnode = malloc(sizeof(i_list));
	if (newnode == NULL)
	{
		free(n);
		return (NULL);
	}
	newnode->a = n;
	newnode->next = NULL;
	if (list == NULL)
		return (newnode);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = newnode;
	return (list);
}

i_list	*make_list(int ac, char **ag, i_list *list)
{
	int		i;
	char	**s;
	char	**tmp;

	s = NULL;
	i = 0;
	while (++i < ac)
	{
		if (!ft_strchr(ag[i], ' '))
			list = check_and_add(ft_atoi(ag[i]), list, s);
		else
		{
			s = ft_split(ag[i], ' ');
			tmp = s;
			if (s == NULL)
				err_message(-1);
			while (*s++ != NULL)
				list = check_and_add(ft_atoi(*s), list, s);
			ft_free(tmp);
		}
	}
	if (!check_duplicates(list))
		handling_invalid_input(NULL, list);
	return (list);
}

// int	num_count(char *s)
// {
// 	int	count;

// 	count = 0;
// 	while (*s != '\0')
// 	{
// 		while (*s != '\0' && ft_isspace(*s))
// 			s++;
// 		while (*s != '\0' && (*s == '-' || *s == '+'))
// 			s++;
// 		if (*s != '\0' && ft_isdigit(*s))
// 		{
// 			while (*s != '\0' && ft_isdigit(*s))
// 				s++;
// 			count++;
// 		}
// 	}
// 	return (count);
// }
