/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:01:23 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/06 14:20:22 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

/*
Used to retrieve the lowest number within a stack.
*/
int	lowest_num(t_stack_item *stack)
{
	int				num;
	t_stack_item	*check;

	num = MAX;
	check = stack;
	while (check)
	{
		if (check->num < num)
			num = check->num;
		check = check->next;
	}
	return (num);
}

/*
Used to retrieve the highest number within a stack.
*/
int	highest_num(t_stack_item *stack)
{
	int				num;
	t_stack_item	*check;

	num = MIN;
	check = stack;
	while (check)
	{
		if (check->num > num)
			num = check->num;
		check = check->next;
	}
	return (num);
}

/*
Used to retrieve the next lowest number within a stack.
*/
int	find_next_lowest(t_stack_item *stack_a, int old_low)
{
	int				new_low;
	t_stack_item	*check;

	new_low = MAX;
	check = stack_a;
	while (check != NULL)
	{
		if (check->num > old_low && check->num < new_low)
			new_low = check->num;
		check = check->next;
	}
	return (new_low);
}

/*
Used to retrieve the the key number to use with chunking.
*/
int	find_key_num(t_stack_item *stack, int size, int chunk)
{
	int				key;
	int				pos;
	t_stack_item	*check;

	key = 0;
	pos = 0;
	check = stack;
	while (pos < ((size * chunk)) && check->next)
	{
		check = check->next;
		pos++;
	}
	key = check->num;
	return (key);
}
