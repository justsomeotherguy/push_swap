/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_to_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:48:32 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/06 15:01:39 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Places the highest and lowest values retrieved earlier in Stack B to their
respective positions in Stack A.
*/
static void	place_in_a(t_stacks *stacks, int highest, int lowest)
{
	while (stacks->b_items > 0)
	{
		if (stacks->stack_b->num == highest)
		{
			pa(stacks);
			ra(stacks, 1);
		}
		else if (stacks->stack_b->num == lowest)
			pa(stacks);
	}
	return ;
}

/*
Retrieves the lowest and highest values to Stack A, then moves them to Stack
B for appropriate sorting after the remaining 3 entries in Stack A has been
sorted.
*/
static void	move_to_b(t_stacks *stacks, int highest, int lowest)
{
	while (stacks->argc > 3)
	{
		if (stacks->stack_a->num == lowest || stacks->stack_a->num == highest)
		{
			pb(stacks);
			stacks->argc--;
		}
		else
			ra(stacks, 1);
	}
	if (stacks->b_items > 1)
	{
		if (stacks->stack_b->num > stacks->stack_b->next->num)
			rb(stacks, 1);
	}
	return ;
}

/*
Preset commands to solve all cases where there is only up to five
numbers to sort.

After shifting to Stack B until only 3 entries remain in Stack A, pass to
the up_to_3 function to handle the 3 entries then move the remaining
numbers in Stack B to Stack A.
*/
void	up_to_5(t_stacks *stacks)
{
	int		highest;
	int		lowest;

	highest = highest_num(stacks->stack_a);
	lowest = lowest_num(stacks->stack_a);
	move_to_b(stacks, highest, lowest);
	up_to_3(stacks);
	stacks->argc = stacks->argc + stacks->b_items;
	place_in_a(stacks, highest, lowest);
	return ;
}
