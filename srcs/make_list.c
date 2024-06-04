/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:12 by hipham            #+#    #+#             */
/*   Updated: 2024/06/04 20:21:42 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freelst(t_list *list)
{
	t_list	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp->content);
		free(tmp);
	}
}

void	print_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_printf("%d\n", *(long int *)tmp->content);
		tmp = tmp->next;
	}
}

t_list	*append_to_lst(t_list *list, long int nbr)
{
	t_list		*newnode;
	t_list		*tmp;
	long int	*n;

	n = malloc(sizeof(long int));
	if (n == NULL)
		return (NULL);
	*n = nbr;
	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
	{
		free(n);
		return (NULL);
	}
	newnode->content = n;
	newnode->next = NULL;
	if (list == NULL)
		return (newnode);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = newnode;
	return (list);
}

t_list	*make_list(int ac, char **ag, t_list *list)
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
