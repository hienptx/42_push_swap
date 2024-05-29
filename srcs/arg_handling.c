/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:09 by hipham            #+#    #+#             */
/*   Updated: 2024/05/29 19:37:15 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_min_max(char *s, int len)
{
	char		*ptr;
	long int	num;

	ptr = ft_calloc(len + 1, sizeof(char));
	if (ptr == NULL)
		return (-1);
	ptr = ft_strncpy(ptr, s, len);
	num = ft_atoi(ptr);
	printf("num = %li\n", num);
	if (num < MIN || num > MAX)
		return (0);
	else
		return (1);
}

int	str_arg_handling(char *s)
{
	int	i;
	int	nbr_count;

	nbr_count = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && ft_isspace(*s))
			s++;
		if (*s != '\0' && (ft_isdigit(*s) || *s == '-' || *s == '+'))
		{
			i = 0;
			while (*s == '-' || *s == '+' || ft_isdigit(*s))
			{
				i++;
				s++;
			}
			nbr_count++;
		}
		else if (*s != '\0' && ft_isprint(*s) && !ft_isdigit(*s))
			return (0);
		if (!check_min_max(s - i, i))
			return (0);
	}
	return (nbr_count);
}

int	num_arg_handling(int ac, char **ag)
{
	int			i;
	long int	num;

	i = 1;
	while (i < ac)
	{
		if (str_arg_handling(ag[i]) > 1 || str_arg_handling(ag[i]) == 0)
			return (0);
		else
		{
			num = ft_atoi(ag[i]);
			if (num < MIN || num > MAX)
				return (0);
		}
		i++;
	}
	return (ac - 1);
}

int	arg_handling(int ac, char **ag)
{
	if (ac == 2)
	{
		if (str_arg_handling(ag[1]) == 0)
			return (0);
		else
			return (str_arg_handling(ag[1]));
	}
	else
	{
		if (num_arg_handling(ac, ag) == 0)
			return (0);
		else
			return (num_arg_handling(ac, ag));
	}
}
