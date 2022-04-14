/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:51:11 by jwilliam          #+#    #+#             */
/*   Updated: 2022/04/06 14:41:59 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Retrieves the entries in Stack A and places them in a new Stack, attempts
to presort all the values before adding them into the presorted stack.
Used to find specific values within the stack for chunking purposes.
*/
void	presort_stack(t_stacks *stacks)
{
	int				lowest;
	int				items_sorted;
	t_stack_item	*check;

	lowest = lowest_num(stacks->stack_a);
	check = stacks->stack_a;
	items_sorted = 0;
	while (items_sorted < stacks->a_items)
	{
		check = stacks->stack_a;
		while (check != NULL)
		{
			if (check->num == lowest)
			{
				add_to_stack(&stacks->sorted_stack, init_stack(check->num));
				items_sorted++;
				lowest = find_next_lowest(stacks->stack_a, lowest);
			}
			check = check->next;
		}
	}
	return ;
}
