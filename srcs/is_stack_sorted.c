/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:32:01 by jwilliam          #+#    #+#             */
/*   Updated: 2022/03/23 16:54:59 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Function to evaluate if the A stack is properly sorted
*/
int	is_stack_sorted(t_stacks *stacks)
{
	t_stack_item	*check_stack;
	int				num;

	check_stack = stacks->stack_a;
	if (stacks->a_items != stacks->argc)
		return (0);
	num = MIN;
	while (check_stack)
	{
		if (check_stack->num < num)
			return (0);
		num = check_stack->num;
		check_stack = check_stack->next;
	}
	return (1);
}
