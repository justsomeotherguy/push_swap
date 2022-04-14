/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:44:04 by jwilliam          #+#    #+#             */
/*   Updated: 2022/03/23 12:14:48 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Take the first element in the top of stack B and puts it at the top of
stack A. Does nothing if stack B is empty.
*/
void	pa(t_stacks *stacks)
{
	t_stack_item	*temp;

	if (stacks->b_items == 0 && !stacks->stack_b)
		return ;
	if (stacks->a_items >= stacks->argc)
		return ;
	temp = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	temp->next = stacks->stack_a;
	stacks->stack_a = temp;
	stacks->a_items++;
	stacks->b_items--;
	print_moves("pa");
	stacks->moves++;
}

/*
Take the first element in the top of stack A and puts it at the top of
stack B. Does nothing if stack A is empty.
*/
void	pb(t_stacks *stacks)
{
	t_stack_item	*temp;

	if (stacks->a_items == 0 && !stacks->stack_a)
		return ;
	if (stacks->b_items >= stacks->argc)
		return ;
	temp = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	temp->next = stacks->stack_b;
	stacks->stack_b = temp;
	stacks->b_items++;
	stacks->a_items--;
	print_moves("pb");
	stacks->moves++;
}
