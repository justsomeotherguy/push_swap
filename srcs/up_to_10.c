/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_to_10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:26 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/06 15:11:27 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function finds the lowest value in Stack A and determines what moves
to use to get to it and move the item to Stack B. Repeats until there is 
only 3 values left in Stack A where it is passed to up_to_3 and all the
items in Stack B are then pushed to Stack A again.
*/
void	up_to_10(t_stacks *stacks)
{
	int		lowest;
	int		split;
	int		num_index;

	while (is_stack_sorted(stacks) == 0)
	{
		lowest = lowest_num(stacks->stack_a);
		split = (stacks->a_items / 2);
		num_index = check_item_pos(stacks->stack_a, lowest);
		if (stacks->a_items <= 3)
		{
			up_to_3(stacks);
			while (stacks->b_items > 0)
				pa(stacks);
			break ;
		}
		if (stacks->stack_a->num == lowest)
			pb(stacks);
		else if (split > num_index)
			ra(stacks, 1);
		else
			rra(stacks, 1);
	}
	return ;
}
