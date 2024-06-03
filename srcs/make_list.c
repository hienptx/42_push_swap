/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:12 by hipham            #+#    #+#             */
/*   Updated: 2024/06/03 22:17:19 by hipham           ###   ########.fr       */
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
		ft_printf("%d ", *(long int *)tmp->content);
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

int	num_count(char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && ft_isspace(*s))
			s++;
		while (*s != '\0' && (*s == '-' || *s == '+'))
			s++;
		if (*s != '\0' && ft_isdigit(*s))
		{
			while (*s != '\0' && ft_isdigit(*s))
				s++;
			count++;
		}
	}
	return (count);
}

void	make_list(int ac, char **ag)
{
	int			i;
	long int	num;
	char		**s;
	t_list		*list;

	list = NULL;
    s = NULL;
	i = 0;
	while (++i < ac)
	{
		ft_printf("number of int = %i\n", num_count(ag[i]));
		if (!ft_strchr(ag[i], ' '))
		{
			num = ft_atoi(ag[i]);
			if (check_validation(num))
				list = append_to_lst(list, num);
			else
				handling_invalid_input(NULL, list);
		}
		else
		{
			s = ft_split(ag[i], ' '); // TODO free s after split
			while (*s != NULL)
			{
				num = ft_atoi(*s);
				if (check_validation(num))
					list = append_to_lst(list, num);
				else
					handling_invalid_input(s, list);
				s++;
			}
		}
	}
	print_list(list);
}
