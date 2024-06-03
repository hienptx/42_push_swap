/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:09 by hipham            #+#    #+#             */
/*   Updated: 2024/06/03 22:18:03 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_min_max(char *s, int len)
// {
// 	char		*ptr;
// 	long int	num;

// 	ptr = ft_calloc(len + 1, sizeof(char));
// 	if (ptr == NULL)
// 		return (-1);
// 	ptr = ft_strncpy(ptr, s, len);
// 	num = ft_atoi(ptr);
// 	printf("num = %li\n", num);
// 	if (num < MIN || num > MAX)
// 		return (0);
// 	else
// 		return (1);
// }
void handling_invalid_input(char **s, t_list *list)
{
	if (!s)
		ft_free(s);
	if (list != NULL)
		ft_freelst(list);
	err_message(1);
}

int check_validation(long int num)
{
	if (num < MIN  || num > MAX)
		return (0);
	return (1);
}

int	str_arg_handling(char *s)
{
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		while (*s != '\0' && ft_isspace(*s))
			s++;
		if (*s != '\0' && (*s == '-' || *s == '+'))
		{
			s++;
			if (*s == '\0')
				return (0);
		}
		if (*s != '\0' && !ft_isdigit(*s))
			return (0);
		if (*s != '\0' && ft_isdigit(*s))
		{
			while (*s != '\0' && ft_isdigit(*s))
				s++;
		}
	}
	return (1);
}

int	num_arg_handling(int ac, char **ag)
{
	int			i;
	long int	num;

	i = 1;
	while (i < ac)
	{
		if (str_arg_handling(ag[i]) == 0)
			return (0);
		else
		{
			num = ft_atoi(ag[i]);
			if (num < MIN || num > MAX)
				return (0);
		}
		i++;
	}
	return (1);
}

int	arg_handling(int ac, char **ag)
{
	if (ac == 2)
	{
		if (!str_arg_handling(ag[1]))
			return (0);
		else
			return (1);
	}
	else
	{
		if (!num_arg_handling(ac, ag))
			return (0);
		else
			return (1);
	}
}
