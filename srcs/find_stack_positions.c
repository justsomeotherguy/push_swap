/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack_positions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:25:08 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/06 14:25:25 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Checks the upper half of a stack for the closest value underneath the
specified key value.
*/
int	check_top_half(t_stack_item *stack, int split, int key)
{
	int				pos;
	t_stack_item	*check;

	pos = 0;
	check = stack;
	while (check->num >= key && pos < split)
	{
		pos++;
		check = check->next;
	}
	return (pos);
}

/*
Checks the lower half of a stack for the closest value underneath the
specified key value.
*/
int	check_bot_half(t_stack_item *stack, int split, int key)
{
	int				pos;
	int				index;
	t_stack_item	*check;

	pos = 0;
	index = 0;
	check = stack;
	while (index < split)
	{
		index++;
		check = check->next;
	}
	while (check != NULL)
	{
		if (check->num < key)
			pos = index;
		index++;
		check = check->next;
	}
	pos = split - pos;
	return (pos);
}

/*
Finds where a specific number in the stack is along with it's position.
*/
int	check_item_pos(t_stack_item *stack, int num_to_find)
{
	int				pos;
	t_stack_item	*check;

	check = stack;
	pos = 0;
	while (check->num != num_to_find && check != NULL)
	{
		pos++;
		check = check->next;
	}
	return (pos);
}
