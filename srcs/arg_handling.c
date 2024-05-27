/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:22:09 by hipham            #+#    #+#             */
/*   Updated: 2024/05/27 21:11:37 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int str_arg_handling(char *s)
{
    int i;
    int nbr_count;

    nbr_count = 0;
    i = 0;
     while (s[i] != '\0')
    {
        while (s[i] != '\0' && ft_isspace(s[i]))
            i++;
        if (s[i] == '-' || s[i] == '+')
            i++;
        if (s[i] != '\0' && ft_isdigit(s[i]) == 1)
        {
            while (s[i] != '\0' && ft_isdigit(s[i]) == 1)
                i++;
            nbr_count++;
        }
        else if (s[i] != '\0' && ft_isprint(s[i]) == 1 && !ft_isdigit(s[i]))
            return 0;
    }
    return nbr_count;
}

int num_arg_handling(int ac, char **ag)
{
    int i;

    i = 1;
    while (i < ac)
    {
        if(str_arg_handling(ag[i]) > 1 || str_arg_handling(ag[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}


int arg_handling(int ac, char **ag)
{
    // coping with a string of numbers: "3 4 6 8 9 74 -56 +495"
    ft_printf("ac = %i\n", ac);
    if(ac == 2)
    {
        if(str_arg_handling(ag[1]) == 0)
        {
            ft_printf("str_arg handling = %i\n", str_arg_handling(ag[1]));
            return 0;
        }
        else
        {
            ft_printf("str_arg handling = %i\n", str_arg_handling(ag[1]));
            return 1;
        }
    }
    else
        // coping with multiple numerical args: 1 3 5 +9 20 -4 50 60 04 0
        if(num_arg_handling(ac, ag) == 0)
            return 0;
        else
            return 1;
}