/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:02:09 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/06 14:40:19 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Initializes a new stack entry. After successfully allocating memory for the
new stack item, return the newly made stack item.
*/
t_stack_item	*init_stack(int num)
{
	t_stack_item		*new_stack;

	new_stack = (t_stack_item *)malloc(sizeof(t_stack_item));
	if (!new_stack)
		return (NULL);
	new_stack->num = num;
	new_stack->next = NULL;
	return (new_stack);
}

/*
Function to add new entries in a linked list stack, retrieves the last
entry in the stack and appends the new entry after it.
*/
void	add_to_stack(t_stack_item **stack, t_stack_item *append)
{
	t_stack_item		*add;

	if (!append)
		return ;
	if (!*stack)
		*stack = append;
	else
	{
		add = to_last_item(*stack);
		add->next = append;
	}
}

/*
Function to retrieve the last entry in a linked list stack.
*/
t_stack_item	*to_last_item(t_stack_item *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}
