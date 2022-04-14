/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:11:02 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/07 14:30:54 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Rotates all of the elements down in stack A by one.
*/
void	rra(t_stacks *stacks, int flags)
{
	t_stack_item	*temp;
	t_stack_item	*prev_first;

	if (!stacks->stack_a || !stacks->stack_a->next)
		return ;
	temp = stacks->stack_a;
	prev_first = stacks->stack_a;
	while (temp->next)
	{
		if (temp->next->next)
			prev_first = prev_first->next;
		temp = temp->next;
	}
	prev_first->next = NULL;
	temp->next = stacks->stack_a;
	stacks->stack_a = temp;
	if (flags == 1)
	{
		print_moves("rra");
		stacks->moves++;
	}
}

/*
Rotates all of the elements down in stack B by one.
*/
void	rrb(t_stacks *stacks, int flags)
{
	t_stack_item	*temp;
	t_stack_item	*prev_first;

	if (!stacks->stack_b || !stacks->stack_b->next)
		return ;
	temp = stacks->stack_b;
	prev_first = stacks->stack_b;
	while (temp->next)
	{
		if (temp->next->next)
			prev_first = prev_first->next;
		temp = temp->next;
	}
	prev_first->next = NULL;
	temp->next = stacks->stack_b;
	stacks->stack_b = temp;
	if (flags == 1)
	{
		print_moves("rrb");
		stacks->moves++;
	}
}

/*
Perform Reverse Rotate A and Reverse Rotate B functions simultaneously.
*/
void	rrr(t_stacks *stacks)
{
	rra(stacks, 0);
	rrb(stacks, 0);
	print_moves("rrr");
	stacks->moves++;
}
