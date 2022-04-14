/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:41:34 by jwilliam          #+#    #+#             */
/*   Updated: 2022/03/23 12:15:21 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Swaps the first two elements at the top of stack A, otherwise do nothing
if there is only one or no elements.
*/
void	sa(t_stacks *stacks, int flags)
{
	int		temp;

	if (stacks->a_items <= 1)
		return ;
	temp = stacks->stack_a->num;
	stacks->stack_a->num = stacks->stack_a->next->num;
	stacks->stack_a->next->num = temp;
	if (flags == 1)
	{
		print_moves("sa");
		stacks->moves++;
	}
}

/*
Swaps the first two elements at the top of stack B, otherwise do nothing
if there is only one or no elements.
*/
void	sb(t_stacks *stacks, int flags)
{
	int		temp;

	if (stacks->b_items <= 1)
		return ;
	temp = stacks->stack_b->num;
	stacks->stack_b->num = stacks->stack_b->next->num;
	stacks->stack_b->next->num = temp;
	if (flags == 1)
	{
		print_moves("sb");
		stacks->moves++;
	}
}

/*
Perform Swap A and Swap B functions simultaneously.
*/
void	ss(t_stacks *stacks)
{
	sa(stacks, 0);
	sb(stacks, 0);
	print_moves("ss");
	stacks->moves++;
}
