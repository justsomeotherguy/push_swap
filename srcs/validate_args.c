/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:09:08 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/08 11:55:25 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

/*
Check if there is duplicate entries received in argv. If a match is found,
goes to the error handling function reporting of duplicate entries.
*/
void	check_stack_dupes(t_stack_item *stack, int match)
{
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->num == match)
			dupe_numbers();
		stack = stack->next;
	}
	return ;
}

/*
Receives a string character array and converts the string into a long
variable. The return value is the long that is created from the conversion.
*/
static long	ft_atol(const char *str)
{
	int			index;
	int			neg;
	long		res;

	index = 0;
	res = 0;
	neg = 1;
	while (str[index] == '\n' || str[index] == '\t' || str[index] == '\r'
		|| str[index] == '\v' || str[index] == '\f' || str[index] == 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			neg = -1;
		index++;
	}	
	while (str[index] != '\0' && ft_isdigit(str[index]))
	{
		res = (res * 10) + str[index] - '0';
		index++;
	}
	if (neg == -1)
		return (-res);
	return (res);
}

/*
Helper function for push_swap main to check whether the input arguments
are valid integers.
*/
int	check_valid_int(int argc, char **argv)
{
	int		argcount;
	int		argvindex;

	argcount = 1;
	argvindex = 0;
	while (argcount < argc)
	{
		while (argv[argcount][argvindex] != '\0')
		{
			if (argv[argcount][argvindex] == '-' && argvindex == 0)
				argvindex++;
			if (!ft_isdigit(argv[argcount][argvindex]))
				invalid_int();
			argvindex++;
		}
		if ((ft_atol(argv[argcount])) >= MAX
			|| (ft_atol(argv[argcount])) <= MIN)
			invalid_int();
		argvindex = 0;
		argcount++;
	}
	return (1);
}
