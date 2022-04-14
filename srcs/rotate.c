/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:46:23 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/07 14:30:57 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Rotates all of the elements up in stack A by one.
*/
void	ra(t_stacks *stacks, int flags)
{
	t_stack_item	*temp;
	t_stack_item	*new_first;

	if (!stacks->stack_a || !stacks->stack_a->next)
		return ;
	temp = stacks->stack_a;
	new_first = stacks->stack_a->next;
	while (stacks->stack_a->next)
		stacks->stack_a = stacks->stack_a->next;
	stacks->stack_a->next = temp;
	temp->next = NULL;
	stacks->stack_a = new_first;
	if (flags == 1)
	{
		print_moves("ra");
		stacks->moves++;
	}	
}

/*
Rotates all of the elements up in stack B by one.
*/
void	rb(t_stacks *stacks, int flags)
{
	t_stack_item	*temp;
	t_stack_item	*new_first;

	if (!stacks->stack_b || !stacks->stack_b->next)
		return ;
	temp = stacks->stack_b;
	new_first = stacks->stack_b->next;
	while (stacks->stack_b->next)
		stacks->stack_b = stacks->stack_b->next;
	stacks->stack_b->next = temp;
	temp->next = NULL;
	stacks->stack_b = new_first;
	if (flags == 1)
	{
		print_moves("rb");
		stacks->moves++;
	}
}

/*
Perform Rotate A and Rotate B functions simultaneously.
*/
void	rr(t_stacks *stacks)
{
	ra(stacks, 0);
	rb(stacks, 0);
	print_moves("rr");
	stacks->moves++;
}
