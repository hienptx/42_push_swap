/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:12 by hipham            #+#    #+#             */
/*   Updated: 2024/06/07 18:16:34 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ilist	*list_new(void *val)
{
	t_ilist	*firstnode;

	firstnode = malloc(sizeof(t_ilist));
	if (firstnode == NULL)
		return (NULL);
	firstnode->a = val;
	firstnode->next = NULL;
	return (firstnode);
}

void	list_add_front(t_ilist **lst, t_ilist *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

t_ilist	*append_to_lst(t_ilist *list, long int nbr)
{
	t_ilist		*newnode;
	t_ilist		*tmp;
	long int	*n;

	n = malloc(sizeof(long int));
	if (n == NULL)
		return (NULL);
	*n = nbr;
	newnode = malloc(sizeof(t_ilist));
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

t_ilist	*check_and_add(long int num, t_ilist *list, char **s)
{
	int	valid;

	valid = 1;
	if (num < MIN || num > MAX)
		valid = 0;
	if (valid)
		list = append_to_lst(list, num);
	else
		handling_invalid_input(s, list);
	return (list);
}

t_ilist	*make_list(int ac, char **ag, t_ilist *list)
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
			if (s == NULL)
				err_message(-1);
			tmp = s;
			while (*s != NULL)
			{
				list = check_and_add(ft_atoi(*s), list, s);
				s++;
			}
			ft_free(tmp);
		}
	}
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
